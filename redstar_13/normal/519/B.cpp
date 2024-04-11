#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[100100],b[100100],c[100100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n-1;i++) scanf("%d",b+i);
	for(int i=1;i<=n-2;i++) scanf("%d",c+i);
	sort(a+1,a+n+1);
	sort(b+1,b+n);b[n]=0;
	sort(c+1,c+n-1);c[n-1]=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]) {cout<<a[i]<<endl;break;}
	}
	for(int i=1;i<=n-1;i++){
		if(c[i]!=b[i]) {cout<<b[i]<<endl;return 0;}
	}
	return 0;
}