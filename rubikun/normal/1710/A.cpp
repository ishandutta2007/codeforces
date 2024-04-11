#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W,K;cin>>H>>W>>K;
        ll asum=0,bsum=0,ama=0,bma=0;
        for(int i=0;i<K;i++){
            ll x;cin>>x;
            if(x/H>=2){
                asum+=x/H;
                chmax(ama,x/H);
            }
            if(x/W>=2){
                bsum+=x/W;
                chmax(bma,x/W);
            }
        }
        bool f=false;
        if(ama>=3){
            if(asum>=W) f=true;
        }else if(ama==2){
            if(asum>=W&&W%2==0) f=true;
        }
        
        if(bma>=3){
            if(bsum>=H) f=true;
        }else if(bma==2){
            if(bsum>=H&&H%2==0) f=true;
        }
        
        if(f) cout<<"Yes\n";
        else cout<<"No\n";
    }
}