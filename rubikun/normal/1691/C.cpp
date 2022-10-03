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
const int mod=1000000009,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        string S;cin>>S;
        vector<int> one;
        for(int i=0;i<N;i++){
            if(S[i]=='1') one.push_back(i);
        }
        
        if(si(one)==0){
            cout<<0<<"\n";
        }else if(si(one)==N){
            cout<<11*(N-1)<<"\n";
        }else if(si(one)==1){
            int l=one[0],r=N-1-one[0];
            if(K>=r){
                cout<<1<<"\n";
            }else if(K>=l){
                cout<<10<<"\n";
            }else{
                cout<<11<<"\n";
            }
        }else{
            int l=one[0],r=N-1-one.back();
            if(K>=l+r){
                int ans=0;
                ans+=(si(one)-2)*11;
                ans+=1;
                ans+=10;
                cout<<ans<<"\n";
            }else if(K>=r){
                int ans=0;
                ans+=(si(one)-1)*11;
                ans+=1;
                cout<<ans<<"\n";
            }else if(K>=l){
                int ans=0;
                ans+=(si(one)-1)*11;
                ans+=10;
                cout<<ans<<"\n";
            }else{
                cout<<si(one)*11<<"\n";
            }
        }
    }
}