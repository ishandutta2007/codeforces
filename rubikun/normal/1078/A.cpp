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
    
    long double a,b,c;cin>>a>>b>>c;
    long double x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    
    long double ans=abs(x1-x2)+abs(y1-y2);
    
    vector<pair<long double,long double>> S1,S2;
    if(a){
        S1.push_back(mp((-b*y1-c)/a,y1));
        S2.push_back(mp((-b*y2-c)/a,y2));
    }
    
    if(b){
        S1.push_back(mp(x1,(-a*x1-c)/b));
        S2.push_back(mp(x2,(-a*x2-c)/b));
    }
    
    for(auto s:S1){
        for(auto t:S2){
            long double dis=0.0;
            dis+=hypot(x1-s.fi,y1-s.se);
            dis+=hypot(s.fi-t.fi,s.se-t.se);
            dis+=hypot(t.fi-x2,t.se-y2);
            
            chmin(ans,dis);
        }
    }
    
    cout<<setprecision(25)<<ans<<endl;
}