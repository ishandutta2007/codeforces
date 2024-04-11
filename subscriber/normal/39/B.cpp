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

int a[222],f[222],p[222],e[222],o=0,ans=0,l=-1,n;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++)if (a[i]==1)f[i]=1;
	for (int i=0;i<n;i++)p[i]=-1;
	for (int i=0;i<n;i++)if (f[i])for (int k=i+1;k<n;k++)if (a[k]==a[i]+1){
		p[k]=i;
		f[k]=1;
	}
	for (int i=0;i<n;i++)if (f[i]&&a[i]>ans){
		ans=a[i];
		l=i;
	}
	while (l!=-1){
		e[o++]=l;
		l=p[l];
	}
	cout << ans << endl;
	for (int i=o-1;i>0;i--)cout << e[i]+2001 << " ";
	if (o)cout << e[0]+2001 << endl;
	return 0;
}