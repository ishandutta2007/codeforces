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
const int mod=1000000007,MAX=3005,INF=1<<29;

string T="aeiou";

bool f(char c){
    for(char x:T) if(c==x) return true;
    return false;
}
int dp[MAX],par[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=si(S);
    for(int i=0;i<MAX;i++) dp[i]=INF;
    dp[0]=0;
    
    for(int i=0;i<N;i++){
        int len=0;
        for(int j=i;j<N;j++){
            if(f(S[j])){
                len=0;
                if(chmin(dp[j+1],dp[i]+1)){
                    par[j+1]=i;
                }
            }else{
                len++;
                if(len<=2){
                    if(chmin(dp[j+1],dp[i]+1)){
                        par[j+1]=i;
                    }
                }else{
                    if(S[j-2]==S[j-1]&&S[j-1]==S[j]){
                        if(chmin(dp[j+1],dp[i]+1)){
                            par[j+1]=i;
                        }
                    }
                    else break;
                }
            }
        }
        
        //for(int j=0;j<=N;j++) cout<<dp[j]<<" ";
        //cout<<endl;
    }
    
    vector<string> ans;
    int now=N;
    while(now>0){
        int p=par[now];
        ans.push_back(S.substr(p,now-p));
        now=p;
    }
    
    reverse(all(ans));
    
    for(int i=0;i<si(ans);i++){
        if(i) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}