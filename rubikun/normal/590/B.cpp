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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    double x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    double x=x2-x1,y=y2-y1;
    double vmax,tmax;cin>>vmax>>tmax;
    double vx,vy,wx,wy;cin>>vx>>vy>>wx>>wy;
    double left=0,right=1e18;
    for(int q=0;q<100;q++){
        double mid=(left+right)/2;
        double gx=x,gy=y;
        gx+=(-vx)*min(mid,tmax);
        gy+=(-vy)*min(mid,tmax);
        gx+=(-wx)*max(0.0,mid-tmax);
        gy+=(-wy)*max(0.0,mid-tmax);
        double d=hypot(gx,gy);
        if(mid*vmax>=d) right=mid;
        else left=mid;
    }
    cout<<fixed<<setprecision(25)<<right<<endl;
}