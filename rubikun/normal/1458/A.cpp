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
    
    int N,M;cin>>N>>M;
    vector<ll> A(N),B(M);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];
    
    sort(all(A));
    ll g=0;
    for(int i=0;i<N-1;i++) g=gcd(g,A[i+1]-A[i]);
    
    for(int i=0;i<M;i++){
        cout<<gcd(g,A[0]+B[i])<<" ";
    }
    cout<<endl;
}