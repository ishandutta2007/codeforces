#include<bits/stdc++.h>

using namespace std;

#define NN 100011
int n;
int cnt[NN];
int a,q;

int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>n;
	for (int i=0; i<n; i++) {
		scanf("%d", &a);
		cnt[i+1] = cnt[i] + a;
	}
	cin>>q;
	while(q--) {
		scanf("%d", &a);
		int k = lower_bound(cnt,cnt+n,a) - cnt;
		printf("%d\n", k);
	}
	return 0;
}