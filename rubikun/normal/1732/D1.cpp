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
    
    int Q;cin>>Q;
    map<ll,ll> MA;
    set<ll> SE;
    while(Q--){
        char c;cin>>c;
        ll x;cin>>x;
        if(c=='+'){
            SE.insert(x);
        }else{
            ll now=x;
            if(MA.count(x)) now=MA[x];
            while(1){
                if(SE.count(now)) now+=x;
                else{
                    cout<<now<<"\n";
                    MA[x]=now;
                    break;
                }
            }
        }
    }
}