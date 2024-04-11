#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

int n,k,a[11111];
long double l,r,c;

bool cn(long double e){
	long double r=0;
	for (int i=0;i<n;i++)if (a[i]>e)r+=(a[i]-e)/100.0*k;else r-=(e-a[i]);
	return r>=0;
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> k;
	k=100-k;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	l=0;
	r=1000;
	while (r-l>1e-8){
		c=(l+r)/2;
		if (cn(c))l=c;else r=c;
	}
	cout.precision(7);
	cout << fixed << l << endl;
	return 0;
}