#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

int a[110];
pii ans[1000];

int main (){
	
	int N,k,i,x;
	scanf("%d %d",&N,&k);
	
	for(i=1; i<=N; i++){
		scanf("%d",a+i);
	}
	
	int M;
	int mx,mn,mxid,mnid;
	
	for(M=0; M<k; M++){
		mx=0, mn=10000, mxid, mnid;
		for(i=1; i<=N; i++){
			if(mx < a[i]) mx=a[i], mxid=i;
			if(mn > a[i]) mn=a[i], mnid=i;
		}
		if(mx-mn<=1) break;
		ans[M]=pii(mxid,mnid);
		a[mxid]--;
		a[mnid]++;
	}
	
	mx=0, mn=10000;
	for(i=1; i<=N; i++){
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	
	printf("%d %d\n",mx-mn, M);
	for(i=0; i<M; i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	
	return 0;
}