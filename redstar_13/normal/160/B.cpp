#include<bits/stdc++.h>
#define NN 110

using namespace std;

int n;
int a[NN],b[NN];
char str[2*NN];
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>n;
	cin>>str;
	for(int i=0; i<n; i++) a[i] = str[i] - '0';
	for(int i=n; i<2*n; i++) b[i-n] = str[i] - '0';	
	sort(a,a+n);
	sort(b,b+n);
	int i;
	for(i=0; i<n; i++) {
		int k=upper_bound(b+i,b+n,a[i]) - b;
		if (k!=i) break;
	}
	if (i==n) puts("YES");
	else {
		for(i=0; i<n;i ++) 
		{
			int k=upper_bound(a+i,a+n,b[i])-a;
			if (i!=k) break;
		}
		if (i==n) puts("YES");
		else puts("NO");
	}
	return 0;
}