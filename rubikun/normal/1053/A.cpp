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
    
    ll N,M,K;cin>>N>>M>>K;
    
    ll S=2*N*M/K;
    
    if(2*N*M%K||S>N*M){
        cout<<"NO\n";
        return 0;
    }
    
    cout<<"YES\n";
    cout<<"0 0\n";
    ll x1,y1,x2,y2;
    
    x1=N;
    y2=(S+N-1)/N;
    
    ll diff=x1*y2-S;
    
    if(N<=M){
        x2=1;
        y1=diff;
    }else{
        x2=diff;
        y1=1;
    }
    
    cout<<x1<<" "<<y1<<"\n";
    cout<<x2<<" "<<y2<<"\n";
}