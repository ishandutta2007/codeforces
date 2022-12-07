#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int ans=2,n,a[111111],p;
long double d;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	if (n==1){
		puts("0");
		return 0;
	}else if (n==2){
		if (a[0]==0&&a[1])puts("1");else puts("0");
		return 0;
	}
	for (int i1=0;i1<2;i1++)for (int i2=i1+1;i2<3;i2++){
		if (a[i1]==0&&a[i2]!=0)continue;
		if (a[i1]==0)d=0;else d=a[i2]/(long double)a[i1];
		p=i2;
		int s=0;
		if (i1!=0||i2!=1)s++;
		for (int i=i2+1;i<n;i++)if (fabs(a[p]*d-a[i])<1e-9)p=i;else s++;
		ans=min(ans,s);
//		cout << i1 << " " << i2 << " " << s << endl;
	}
	cout << ans << endl;
	return 0;
}