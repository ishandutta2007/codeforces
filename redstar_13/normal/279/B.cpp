#include <bits/stdc++.h>

using namespace std;
#define MM 110000

int n, sum[MM], a[MM], ans, t;
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("in.in", "r", stdin);
	freopen ("out.out", "w", stdout);
#endif
	scanf ("%d%d", &n, &t); sum[0]=0;
	for (int i=1; i<=n; i++){
		 scanf ("%d", a+i);
		 sum[i]=sum[i-1]+a[i];
	}
	int st=0, ed=1;
	while(1){
		while(sum[ed]-sum[st]<=t && ed<=n)ed++;
		ans=max(ed-st-1, ans);
		if(ed==n+1) break;
		st++;
	}
	cout<<ans<<endl;
	return 0;
}