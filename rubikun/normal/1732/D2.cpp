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

set<ll> aru[MAX];
map<ll,vector<pair<ll,ll>>> po;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    vector<pair<char,ll>> que(Q);
    map<ll,ll> MA;
    set<ll> SE;
    for(int q=0;q<Q;q++){
        char c;cin>>c;
        ll x;cin>>x;
        if(c=='+'){
            SE.insert(x);
        }else if(c=='?'){
            ll now=x;
            if(MA.count(x)) now=MA[x];
            while(1){
                if(SE.count(now)) now+=x;
                else{
                    //cout<<now<<"\n";
                    MA[x]=now;
                    break;
                }
            }
        }
        que[q]=(mp(c,x));
    }
    
    vector<ll> use;
    for(auto a:MA){
        for(ll i=1;i<=a.se/a.fi;i++){
            aru[si(use)].insert(i);
            po[a.fi*i].push_back(mp(si(use),i));
        }
        use.push_back(a.fi);
    }
    
    for(int q=0;q<Q;q++){
        auto [c,x]=que[q];
        if(c=='+'){
            for(auto z:po[x]){
                aru[z.fi].erase(z.se);
            }
        }else if(c=='-'){
            for(auto z:po[x]){
                aru[z.fi].insert(z.se);
            }
        }else{
            int k=lower_bound(all(use),x)-use.begin();
            cout<<*aru[k].begin()*x<<"\n";
        }
        //que[q]=(mp(c,x));
    }
    
    
}