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
const int mod=998244353,MAX=1<<18;
const ll INF=1LL<<60;

string T[MAX];

ll ans=1;

int N;

void solve(int u){
    if(2*u>N) return;
    solve(2*u);
    solve(2*u+1);
    if(T[2*u]!=T[2*u+1]){
        ans*=2;
        ans%=mod;
    }
    string A=T[2*u],B=T[2*u+1];
    if(A>B) swap(A,B);
    T[u]=T[u]+A+B;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M;cin>>M;
    N=(1<<M)-1;
    string S;cin>>S;
    for(int i=0;i<N;i++){
        T[i+1]+=S[i];
    }
    
    solve(1);
    
    //for(int i=1;i<=M;i++) cout<<T[i]<<endl;
    
    cout<<ans<<endl;
}