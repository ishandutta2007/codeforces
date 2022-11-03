#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll k;
int f[100005],w[100005];
int nxt[35][100005];
ll nxw[35][100005];
ll nxm[35][100005];

int main(){
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",f+i);
		nxt[0][i]=f[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",w+i);
		nxw[0][i]=w[i];
		nxm[0][i]=w[i];
	}
	for(int i=1;i<35;i++){
		for(int j=0;j<n;j++){
			nxt[i][j]=nxt[i-1][nxt[i-1][j]];
			nxw[i][j]=nxw[i-1][j]+nxw[i-1][nxt[i-1][j]];
			nxm[i][j]=min(nxm[i-1][j],nxm[i-1][nxt[i-1][j]]);
		}
	}
	for(int i=0;i<n;i++){
		int now=i;
		ll val=0,mn=0x3f3f3f3f;
		for(int i=0;i<35;i++){
			if((k>>i)&1){
				val+=nxw[i][now];
				mn=min(mn,nxm[i][now]);
				now=nxt[i][now];
			}
		}
		printf("%lld %lld\n",val,mn);
	}
	return 0;
}