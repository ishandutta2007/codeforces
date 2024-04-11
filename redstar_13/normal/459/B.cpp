#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[202000];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	INT s;
	if(a[1]==a[n]) s=(INT)n*(n-1)/2;
	else {
		INT t=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==a[1]) t++;
			else break;
		}
		INT r=0;
		for(int i=n;i>=1;i--) {
			if(a[i]==a[n]) r++;
			else break;
		}
		s=t*r;
	}
	cout<<a[n]-a[1]<<" "<<s<<endl;
	return 0;
}