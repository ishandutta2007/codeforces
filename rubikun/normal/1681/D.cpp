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
const int mod=998244353,MAX=105,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,X;cin>>N>>X;
    ll want=1;
    for(int i=0;i<N-1;i++) want*=10;
    
    queue<ll> Q;
    map<ll,int> MA;
    MA[X]=0;Q.push(X);
    
    while(!Q.empty()){
        ll x=Q.front();Q.pop();
        ll n=x;
        while(n){
            ll y=n%10;
            if(!MA.count(x*y)){
                if(x*y>=want){
                    cout<<MA[x]+1<<"\n";
                    return 0;
                }
                MA[x*y]=MA[x]+1;
                Q.push(x*y);
            }
            n/=10;
        }
    }
    
    cout<<-1<<endl;
}