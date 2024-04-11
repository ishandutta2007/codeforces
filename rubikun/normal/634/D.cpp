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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll D,lim,M;cin>>D>>lim>>M;
    vector<ll> use;
    use.push_back(0);
    use.push_back(lim);
    use.push_back(D);
    vector<pair<ll,ll>> S(M+1);
    for(int i=0;i<M;i++){
        ll x,p;cin>>x>>p;
        use.push_back(x);
        use.push_back(min(D,x+lim));
        S[i]=mp(x,p);
    }
    sort(all(S));
    for(int i=0;i+1<si(S);i++){
        if(S[i+1].fi-S[i].fi>lim){
            cout<<-1<<"\n";
            return 0;
        }
    }
    if(D-S.back().fi>lim){
        cout<<-1<<"\n";
        return 0;
    }
    
    sort(all(use));
    use.erase(unique(all(use)),use.end());
    
    //for(ll a:use) cout<<a<<" ";
    //cout<<endl;
    
    ll ans=0;
    
    set<pair<ll,int>> SE;
    
    int j=0,k=0;
    
    for(int i=0;i+1<si(use);i++){
        while(j<si(S)&&S[j].fi==use[i]){
            SE.insert(mp(S[j].se,j));
            j++;
        }
        while(k<si(S)&&S[k].fi+lim==use[i]){
            SE.erase(mp(S[k].se,k));
            k++;
        }
        ans+=(*SE.begin()).fi*(use[i+1]-use[i]);
    }
    
    cout<<ans<<"\n";
}