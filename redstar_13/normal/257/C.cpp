#include<bits/stdc++.h>
using namespace std;
#define pi 3.141592653589793238462643
double Q[100100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,x,y;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(x>=0){
			if(y>=0) Q[i]=asin(y/hypot(x,y))*180/acos(-1);
			if(y<0) Q[i]=asin(y/hypot(x,y))*180/acos(-1)+360;
		}
		if(x<0){
			Q[i]=180-asin(y/hypot(x,y))*180/acos(-1);
		}
	}
	sort(Q+1,Q+n+1);
	Q[n+1]=360+Q[1];
	double mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,Q[i+1]-Q[i]);
	}
	printf("%.8lf",360-mx);
	return 0;
}