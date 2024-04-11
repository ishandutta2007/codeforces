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
    
    ll k,d,t;cin>>k>>d>>t;
    ll x=(k+d-1)/d*d;
    ll on=k,off=x-k;
    
    ll all=t*2;
    
    ll ans=0;
    ans+=all/(on*2+off)*(on+off);
    all-=all/(on*2+off)*(on*2+off);
    
    if(all<=on*2){
        double anss=ans;
        anss+=all/2.0;
        cout<<setprecision(25)<<anss<<endl;
    }else{
        ans+=on;
        all-=on*2;
        ans+=all;
        cout<<ans<<endl;
    }
}