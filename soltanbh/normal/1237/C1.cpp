#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll mn,a,mark[20009],n,x[2009],y[2009],z[2009];
int main(){
	cin>>n;
	f(i,0,n) cin>>x[i]>>y[i]>>z[i];
	f(i,0,n-1){
		if(mark[i]==0){
			mark[i]=1;
			mn=1e18,a=-1;
			f(j,0,n){
				if(mark[j]==0){
					if((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])+(z[j]-z[i])*(z[j]-z[i])<mn){
						mn=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])+(z[j]-z[i])*(z[j]-z[i]);
						a=j;
					}
				}
			}
			mark[a]=1;
			cout<<i+1<<" "<<a+1<<endl;
		}
	}
}