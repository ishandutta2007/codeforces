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
const int mod=1000000007,MAX=2000005,INF=1<<30;

ll a[MAX],b[MAX],c[MAX],x[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    a[1]=1;
    b[1]=0;
    c[1]=0;
    
    for(int i=2;i<=2000000;i++){
        a[i]=(a[i-1]+2*b[i-1])%mod;
        b[i]=a[i-1];
        c[i]=(b[i-1]+c[i-1])%mod;
        x[i]=(mod+c[i]-c[i-1])%mod;
    }
    
    for(int i=3;i<=2000000;i++){
        x[i]+=x[i-3];
        x[i]%=mod;
    }
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        cout<<(x[N]*4)%mod<<"\n";
    }
}