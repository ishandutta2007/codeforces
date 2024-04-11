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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        string S;cin>>S;
        vector<int> rui(N+1);
        for(int i=1;i<=N;i++){
            rui[i]=rui[i-1]+(S[i-1]=='1');
        }
        ll a=rui[N],b=N-a;
        if((a*K)%N){
            cout<<-1<<"\n";
            continue;
        }
        ll aa=a*K/N,bb=K-aa;
        int ans=-1;
        for(int i=0;i+K<=N;i++){
            if(rui[i+K]-rui[i]==aa){
                ans=i;
            }
        }
        if(ans!=-1){
            cout<<1<<"\n";
            cout<<ans+1<<" "<<ans+K<<"\n";
            continue;
        }
        for(int i=0;i<=K;i++){
            if(rui[i]+rui[N]-rui[N-(K-i)]==aa){
                ans=i;
            }
        }
        if(ans!=-1){
            cout<<2<<"\n";
            cout<<1<<" "<<ans<<"\n";
            cout<<N-(K-1-ans)<<" "<<N<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}