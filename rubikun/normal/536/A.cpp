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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll A,B,Q;cin>>A>>B>>Q;
    while(Q--){
        ll l,t,m;cin>>l>>t>>m;
        if(A+(l-1)*B>t){
            cout<<-1<<"\n";
            continue;
        }
        ll left=l,right=t*m;
        while(right-left>1){
            ll mid=(left+right)/2;
            ll ma=A+(mid-1)*B;
            ll mi=A+(l-1)*B;
            if(ma<=t){
                ll sum=(mi+ma)*(mid-(l-1))/2;
                if(sum<=t*m) left=mid;
                else right=mid;
            }else{
                right=mid;
            }
        }
        cout<<left<<"\n";
    }
}