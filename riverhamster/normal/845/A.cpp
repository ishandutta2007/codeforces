#include <bits/stdc++.h>
using namespace std;
int a[205];
int ma=0,mb=0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n*2);
	//printf("Debug:a[n]=%d,a[n+1]=%d\n",a[n],a[n+1]);
	if(a[n]<a[n+1]) puts("YES");
	else puts("NO");
	return 0;
}