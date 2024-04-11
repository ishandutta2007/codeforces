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
    
    int X,Y;cin>>X>>Y;
    double x,y;
    {
        vector<double> askx,asky;
        for(int i=0;i<Y;i++){
            asky.push_back(i);
            askx.push_back(X);
            
            asky.push_back(i+0.5);
            askx.push_back(0);
        }
        
        asky.push_back(Y);
        askx.push_back(X);
        
        asky.push_back(Y);
        askx.push_back(2*X);
        
        cout<<"? "<<si(askx)<<endl;
        for(int i=0;i<si(askx);i++){
            cout<<fixed<<setprecision(12)<<askx[i]<<" "<<asky[i]<<endl;
        }
        
        double res;cin>>res;
        
        x=(res*2*X-1.0)/2.0;
    }
    {
        vector<double> askx,asky;
        for(int i=0;i<X;i++){
            asky.push_back(Y);
            askx.push_back(i);
            
            asky.push_back(0);
            askx.push_back(i+0.5);
        }
        
        asky.push_back(Y);
        askx.push_back(X);
        
        asky.push_back(2*Y);
        askx.push_back(X);
        
        cout<<"? "<<si(askx)<<endl;
        for(int i=0;i<si(askx);i++){
            cout<<fixed<<setprecision(12)<<askx[i]<<" "<<asky[i]<<endl;
        }
        
        double res;cin>>res;
        
        y=(res*2*Y-1.0)/2.0;
    }
    
    cout<<"! ";
    cout<<fixed<<setprecision(12)<<x<<" "<<y<<endl;
    
}