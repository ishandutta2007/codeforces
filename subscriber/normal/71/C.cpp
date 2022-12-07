#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,a[111111],f[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int d=1;d<=n;d++)if (n%d==0){
		if (n/d<3)break;
		for (int i=0;i<d;i++)f[i]=a[i];
		for (int i=d;i<n;i++)if (!a[i])f[i]=0;else f[i]=f[i-d]+1;
		int t=0;
		for (int i=0;i<n;i++)if (f[i]==n/d)t=1;
		if (t){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}