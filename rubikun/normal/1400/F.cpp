#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=1005;
const int INF=1<<30;
map<int,int> dp[MAX];

bool out[25];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;cin>>s;
    int N=si(s);
    vector<int> S(N);
    for(int i=0;i<N;i++) S[i]=int(s[i]-'0');
    int x;cin>>x;
    dp[0][0]=0;
    
    for(int i=1;i<x;i++) if(x%i==0) out[i]=1;
    
    int V=(1<<x)-1;
    
    int con=INF;
    
    for(int i=0;i<N;i++){
        int mi=INF;
        for(auto j:dp[i]){
            int a=j.fi,b=j.se;
            
            if(b>=con) continue;
            
            if(out[S[i]]){
                if(dp[i+1].count(0)==0) dp[i+1][0]=b;
                else chmin(dp[i+1][0],b);
                
                chmin(mi,b);
                continue;
            }
            
            int mae=a;
            a<<=S[i];
            a|=(1<<(S[i]-1));
            a&=V;
            
            bool check=false;
            
            if(a&(1<<(x-1))){
                check=true;
                for(int k=0;k<x;k++){
                    if(a&(1<<k)){
                        for(int l=k+1;l<x;l++){
                            if(a&(1<<l)){
                                if(out[l-k]) check=false;
                            }
                            if(!check) break;
                        }
                        if(out[k+1]) check=false;
                    }
                    if(!check) break;
                }
            }
            
            //cout<<i<<" "<<bitset<7>(a)<<" "<<b<<" "<<check<<endl;
            
            if(!check){
                if(dp[i+1].count(a)==0) dp[i+1][a]=b;
                else chmin(dp[i+1][a],b);
                
                chmin(mi,b);
            }
            
            if(dp[i+1].count(mae)==0) dp[i+1][mae]=b+1;
            else chmin(dp[i+1][mae],b+1);
            
            chmin(mi,b+1);
        }
        
        con=mi+x;
        
        dp[i].clear();
    }
    
    int ans=INF;
    
    for(auto j:dp[N]) chmin(ans,j.se);
    
    cout<<ans<<endl;
}