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
const int mod=1000000007,MAX=200005,INF=1<<30;
int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,l,v1,v2,k;cin>>N>>l>>v1>>v2>>k;
    
    int x=(N+k-1)/k;
    
    double t=double(l)/(double(x)*v2-double(v2-v1)*v2/(v1+v2)*(x-1));
    
    double ans=t+double(l-t*v2)/v1;
    cout<<setprecision(25)<<ans<<endl;
}