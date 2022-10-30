#include<bits/stdc++.h>
#define NN 200011

using namespace std;

int n,m;
int l1[NN], r1[NN],l2[NN], r2[NN];
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin>>n;
	for(int i=0; i<n; i++) 
		scanf("%d%d",&l1[i], &r1[i]);
	cin>>m;
	for(int i=0; i<m; i++) scanf("%d%d", &l2[i],&r2[i]);
	sort(r1,r1+n);
	sort(l1,l1+n);
	sort(r2,r2+m);
	sort(l2,l2+m);
	int mx = max(l2[m-1]-r1[0],l1[n-1]-r2[0]);
	if (mx<0) mx=0;
	cout<<mx<<endl;
	return 0;
}