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
    
    ll N;cin>>N;
    if(N==2){
        cout<<1<<endl;
    }else if(N%2==0){
        cout<<2<<endl;
    }else{
        bool ok1=true,ok2=true;
        for(ll i=2;i*i<=N;i++){
            if(N%i==0) ok1=false;
            if((N-2)%i==0) ok2=false;
        }
        if(ok1) cout<<1<<endl;
        else if(ok2) cout<<2<<endl;
        else cout<<3<<endl;
    }
}