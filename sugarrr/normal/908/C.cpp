

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
typedef long long ll;
using namespace std;




int main(){
    int n;cin>>n;
    double r;cin>>r;
    double x[n+1];
    double y[n+1];
    for(int i=1;i<=n;i++)scanf("%lf",&x[i]);
    
    for(int i=1;i<=n;i++){
        double ans=r;
        for(int j=1;j<=i-1;j++){
            double mayans=-1;
            if(x[j]-2*r<=x[i]&&x[i]<=x[j]+2*r){
                mayans=y[j]+sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j]));
                if(mayans>ans)ans=mayans;
            }
        }
        y[i]=ans;
        printf("%f ",y[i]);
    }
    
    
    
    return 0;
}