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
    
    int N;cin>>N;
    vector<ll> A(N),sum(4*N);
    for(int i=0;i<N;i++) cin>>A[i];
    int now=0;
    sum[0]=0;
    int id=1;
    while(id<4*N){
        sum[id]=sum[id-1]+A[now];
        now+=2;
        now%=N;
        id++;
    }
    
    ll res=0;
    
    for(int i=N/2+1;i<4*N;i++){
        chmax(res,sum[i]-sum[i-1-N/2]);
    }
    
    cout<<res<<endl;
}