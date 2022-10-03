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
const int mod=998244353,MAX=300005,INF=1<<30;
vector<pair<ll,ll>> S[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    ll ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int a;cin>>a;a--;
            S[a].push_back(mp(i,j));
        }
    }
    
    for(int c=0;c<100000;c++){
        sort(all(S[c]),[](auto a,auto b){
            return a.fi<b.fi;
        });
        ll sum=0;
        for(int i=0;i<si(S[c]);i++){
            ans+=S[c][i].fi*i-sum;
            sum+=S[c][i].fi;
        }
        sort(all(S[c]),[](auto a,auto b){
            return a.se<b.se;
        });
        sum=0;
        for(int i=0;i<si(S[c]);i++){
            ans+=S[c][i].se*i-sum;
            sum+=S[c][i].se;
        }
    }
    
    cout<<ans<<"\n";
}