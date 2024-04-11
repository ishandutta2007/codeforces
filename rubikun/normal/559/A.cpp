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
const int mod=998244353,MAX=3005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll ans=0;
    vector<ll> A(6);
    for(int i=0;i<6;i++) cin>>A[i];
    ll M=A[1]+A[2];
    vector<ll> S(M+1),T(M+1);
    S[0]=T[0]=A[0];
    for(int i=1;i<=A[1];i++) S[i]=S[i-1]+1;
    for(int i=A[1]+1;i<=M;i++) S[i]=S[i-1]-1;
    for(int i=1;i<=A[5];i++) T[i]=T[i-1]+1;
    for(int i=A[5]+1;i<=M;i++) T[i]=T[i-1]-1;
    for(int i=0;i<M;i++){
        ans+=(S[i]+S[i+1]+T[i]+T[i+1])/2;
    }
    cout<<ans<<endl;
}