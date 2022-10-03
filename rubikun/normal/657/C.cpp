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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    ll X,Y;cin>>X>>Y;
    chmin(X,Y*5);
    
    vector<ll> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    sort(all(S));
    for(int i=1;i<N;i++) S[i]-=S[0];
    S[0]=0;
    
    ll ans=INF;
    
    for(int d=0;d<5;d++){
        vector<pair<ll,ll>> T(N);
        for(int i=0;i<N;i++){
            ll need=(d+5-S[i]%5)%5;
            T[i]=mp((S[i]+need)/5,need*Y);
        }
        sort(all(T));
        
        ll sum=0;
        
        priority_queue<ll> PQ;
        
        int j=0;
        for(int i=0;i<N;i++){
            while(j<N&&T[j].fi==T[i].fi){
                PQ.push(-T[j].fi*X+T[j].se);
                sum+=-T[j].fi*X+T[j].se;
                if(si(PQ)>K){
                    sum-=PQ.top();PQ.pop();
                }
                j++;
            }
            if(si(PQ)==K){
                chmin(ans,sum+T[i].fi*X*K);
            }
        }
    }
    
    cout<<ans<<endl;
}