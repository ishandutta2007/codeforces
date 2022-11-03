#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int ff[2000005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		ff[a[i]]++;
	}
	int jw=0;
	for(int i=0;i<=1999999;i++){
		ff[i]+=jw;
		jw=ff[i]/2;
		ff[i]%=2;
	}
	int cnt=0;
	for(int i=0;i<=1999999;i++){
		cnt+=ff[i];
	}
	printf("%d\n",cnt);
	return 0;
}