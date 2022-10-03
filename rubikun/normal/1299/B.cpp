#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
const long double eps=1e-8;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> x(N),y(N);
    long double xsum=0.0,ysum=0.0;
    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
        xsum+=x[i];
        ysum+=y[i];
    }
    
    xsum/=(long double)N;
    ysum/=(long double)N;
    
    vector<int> d;
    for(int i=1;i<N;i++){
        if(N%i==0) d.push_back(i);
    }
    
    bool ans=false;
    
    for(int t:d){
        bool ok=true;
        //if(abs(hypot(x[0]-xsum,y[0]-ysum)-hypot(x[t]-xsum,y[t]-ysum))>eps) continue;
        //long double p=atan2(y[t]-y[0],x[t]-x[0]);
        
        for(int i=0;i<N;i++){
            //long double pp=atan2(y[(i+t)%N]-y[i],x[(i+t)%N]-x[i]);
            //if(abs(p-pp))
            if(abs(hypot((long double)x[(i+t)%N]-xsum,(long double)y[(i+t)%N]-ysum)-hypot((long double)x[i]-xsum,(long  double)y[i]-ysum))>eps) ok=false;
        }
        if(ok) ans=true;
    }
    
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}