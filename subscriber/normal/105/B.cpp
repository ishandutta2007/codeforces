#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>

using namespace std;

int n,k,W,w[10],p[10];
long double ans=0;

void gg(){
	long double aa=0;
	for (int o=0;o<(1<<n);o++){
		long double q=1;
		for (int i=0;i<n;i++)if (o&(1<<i))q*=p[i]/100.;else q*=(100-p[i])/100.;
		int t=0,s=0;
		for (int i=0;i<n;i++)if (o&(1<<i))t++;else s+=w[i];
		if (t>n/2)aa+=q;else aa+=q*(W/1./(W+s));

	}
	ans=max(ans,aa);
}

void rec(int l,int o){
	if (l==n){
		gg();
		return;
	}
	if (p[l]<100&&o){
		p[l]+=10;
		rec(l,o-1);
		p[l]-=10;
	}
	rec(l+1,o);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k >> W;
	for (int i=0;i<n;i++)cin >> w[i] >> p[i];
	rec(0,k);
	cout.precision(6);
	cout << fixed << ans << endl;
	return 0;
}