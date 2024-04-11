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

pair<double,double> solve(double x,double y){
    double a=(x-sqrt(x*x-4*y))/2.0,b=(x+sqrt(x*x-4*y))/2.0;
    return mp(a,b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<double> M(N),m(N),A(N),B(N);
    for(int i=0;i<N;i++) cin>>M[i];
    for(int i=0;i<N;i++) cin>>m[i];
    
    double asum=0,bsum=0,Msum=0,msum=0;
    for(int i=0;i<N-1;i++){
        Msum+=M[i];
        msum+=m[i];
        auto res=solve(Msum+msum,Msum);
        A[i]=res.fi-asum;
        B[i]=res.se-bsum;
        asum=res.fi;
        bsum=res.se;
    }
    
    A.back()=1.0-asum;
    B.back()=1.0-bsum;
    
    for(int i=0;i<N;i++) cout<<fixed<<setprecision(25)<<A[i]<<" ";
    cout<<endl;
    
    for(int i=0;i<N;i++) cout<<fixed<<setprecision(25)<<B[i]<<" ";
    cout<<endl;
}