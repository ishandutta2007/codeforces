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
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M;cin>>M;
    set<ll> ok;
    for(int q=0;q<2;q++){
        ll h,a,x,y;cin>>h>>a>>x>>y;
        vector<ll> A;
        for(ll t=1;t<=3*M;t++){
            h=(x*h+y)%M;
            if(h==a) A.push_back(t);
        }
        if(si(A)==0){
            cout<<-1<<"\n";
            return 0;
        }
        ll b=A[0],syuu=A[1]-A[0];
        if(q==0){
            for(int i=0;i<2*M;i++) ok.insert(b+syuu*i);
        }else{
            for(int i=0;i<2*M;i++){
                if(ok.count(b+syuu*i)){
                    cout<<b+syuu*i<<"\n";
                    return 0;
                }
            }
            cout<<-1<<"\n";
        }
    }
}