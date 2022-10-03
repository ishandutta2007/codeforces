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
const int mod=1000000007,MAX=2005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll p,k;cin>>p>>k;
    vector<ll> A={k,1},B(300),C(301);
    ll now=p;
    
    for(int i=0;i<299;i++){
        if(i&1){
            B[i]=((now+k-1)/k);
            now=(now+k-1)/k;
        }else{
            B[i]=-(now/k);
            now=now/k;
        }
    }
    
    for(int a=0;a<2;a++){
        for(int b=0;b<300;b++){
            C[a+b]+=A[a]*B[b];
        }
    }
    
    C[0]+=p;
    
    int ma=-1;
    for(int i=0;i<301;i++) if(C[i]) chmax(ma,i);
    
    cout<<ma+1<<endl;
    for(int i=0;i<=ma;i++) cout<<C[i]<<" ";
    cout<<endl;
    
    
}