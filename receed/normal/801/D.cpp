#include <bits/stdc++.h>

using namespace std;

vector<long long>x(100000),y(100000);
int n;
long double d(int i,int j){
    return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
long double s(int i){
    int j=(i+1)%n, k=(j+1)%n;
    return abs((x[i]-x[j])*(y[i]+y[j])+(x[j]-x[k])*(y[j]+y[k])+(x[k]-x[i])*(y[k]+y[i]));
}


int main()
{
    int j,k;
    cin>>n;
    long double ans=2000000000000,t;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for(int i=0;i<n;i++){
        t=d(i,(i+1)%n)/2;
        if(t<ans) ans=t;
    }
    for(int i=0;i<n;i++){
        t=s(i)/d(i,(i+2)%n)/2;
        if(ans>t) ans=t;
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}