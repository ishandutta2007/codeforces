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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;
#define double long double

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    double M;cin>>N>>M;
    vector<double> A(N),B(N);
    
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    
    double left=0,right=1.2e9;
    
    for(int q=0;q<100;q++){
        double mid=(left+right)/2.0;
        
        bool ok=true;
        double now=M+mid;
        for(int i=0;i<N;i++){
            now-=now/A[i];
            if(now<=M) ok=false;
            now-=now/B[(i+1)%N];
            if(now<=M) ok=false;
        }
        
        if(ok) right=mid;
        else left=mid;
    }
    
    if(right>1.1e9) cout<<-1<<endl;
    else cout<<fixed<<setprecision(25)<<right<<endl;
}