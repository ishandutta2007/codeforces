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
    
    int x,y,z,t1,t2,t3;cin>>x>>y>>z>>t1>>t2>>t3;
    
    int A=abs(x-z)*t2+3*t3+abs(x-y)*t2;
    int B=abs(x-y)*t1;
    
    if(A<=B) cout<<"YES\n";
    else cout<<"NO\n";
}