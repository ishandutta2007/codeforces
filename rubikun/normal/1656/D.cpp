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
const ll INF=1LL<<60;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N;cin>>N;
        bool f=true;
        ll a=1;
        while(N%2==0){
            a*=2;
            N/=2;
        }
        if(N==1){
            cout<<-1<<"\n";
        }else{
            ll b=N;
            if(2*a>b){
                cout<<b<<"\n";
            }else{
                cout<<2*a<<"\n";
            }
        }
    }
}