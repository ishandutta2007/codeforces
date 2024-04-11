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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    ll g=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        g=gcd(g,A[i]);
    }
    bool ok=true;
    
    for(int i=0;i<N;i++){
        A[i]/=g;
        while(A[i]%2==0){
            A[i]/=2;
        }
        while(A[i]%3==0){
            A[i]/=3;
        }
        if(A[i]!=1) ok=false;
    }
    
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}