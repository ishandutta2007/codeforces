#include<bits/stdc++.h>
#define NN 1011

using namespace std;

int n;
int a[NN], b[NN];
int flag[NN];
int mn,mx;
int ans;
char s[NN];

int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>n;
	scanf(" %s",s);
	for(int i=0; i<n; i++) a[i] = s[i]-'0';
	sort(a,a+n);
	scanf(" %s",s);
	for(int i=0; i<n; i++) b[i] = s[i] - '0';
	sort(b,b+n);
	int k=-1,i;
	for(i=0; i<n; i++) {
		k=lower_bound(b+k+1,b+n,a[i])-b;
		if (k==n) {
			ans=i; break;
		}
	}
	if (i==n) puts("0");
	else printf("%d\n", n-ans);
	k=-1;
	for(i=0; i<n; i++) {
		k=upper_bound(b+k+1,b+n,a[i])-b;
		if (k==n) {
			ans=i; break;
		}
	}	
	if (i==n) printf("%d\n", n);
	else printf("%d\n", ans);
	return 0;
}