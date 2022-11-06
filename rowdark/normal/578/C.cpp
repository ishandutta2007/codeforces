#include<stdio.h>
#include<iostream>
#include<algorithm>
int n;
int a[200001];
long double l,r;
long double Abs(const long double &x){
	return x<0?-x:x;
}
inline long double getans(long double delta){
	long double minv=0,maxv=0,sum=0,ret=0;
	for(int i=1;i<=n;++i){
		sum+=a[i]+delta;
		ret=std::max(std::max(Abs(sum-minv),Abs(sum-maxv)),ret);
		minv=std::min(minv,sum);
		maxv=std::max(maxv,sum);
	}
	return ret;
}
int main(){
	l=-10000,r=10000;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=100;++i){
		long double mid1=l+(r-l)/3;
		long double mid2=l+(r-l)/3*2;
		long double ans1=getans(mid1);
		long double ans2=getans(mid2);
		if(ans1<ans2) r=mid2;
		else l=mid1;
	}
	printf("%.10f\n",double(getans((l+r)/2)));
	return 0;
}