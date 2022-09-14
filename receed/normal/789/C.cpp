#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>a(n),f(n-1),p(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++){
        f[i]=abs(a[i]-a[i+1]);
        p[i+1]=p[i]+f[i]*(1-i%2*2);
    }
    long long min1=2000000001,min2=0;
    long long ans=-2000000*2000000;
    for(int i=1;i<n;i++){
        //cout<<p[i]<<endl;
        ans=max(ans,-p[i]-min1);
        ans=max(ans,p[i]-min2);
        if(i%2==0){
            min2=min(min2,p[i]);
        }
        else{
            min1=min(min1,-p[i]);
        }
    }
    cout<<ans;
}