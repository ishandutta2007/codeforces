/*
ID: Sfiction
OJ: CF
PROB: 512B
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=300;
const int INF=1<<30;

int n;
int len[MAXN],cost[MAXN];

int fac[MAXN*10],lenf;
bool p[MAXN][MAXN*10];
int list[MAXN][10];

int min[1<<10];

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&len[i]);
	for (int i=0;i<n;++i)
		scanf("%d",&cost[i]);
	lenf=0;
	for (int i=0;i<n;++i){
		int t=len[i];
		for (int j=2;j*j<=t;++j)
			if (t%j==0){
				fac[lenf++]=j;
				for (;t%j==0;t/=j);
			}
		if (t>1)
			fac[lenf++]=t;
	}
	std::sort(fac,fac+lenf);
	int templen=lenf;
	lenf=0;
	for (int i=0;i<templen;++i)
		if (i==0 || fac[i]!=fac[i-1])
			fac[lenf++]=fac[i];
	memset(p,0,sizeof(p));
	for (int i=0;i<n;++i){
		list[i][0]=0;
		for (int j=0;j<lenf;++j)
			if (len[i]%fac[j]==0){
				p[i][j]=true;
				list[i][++list[i][0]]=j;
			}
	}

	int ans=INF;
	for (int i=0;i<n;++i){
		int m=(1<<list[i][0])-1;
		for (int j=m;j>=0;--j)
			min[j]=INF;
		min[0]=cost[i];
		for (int j=0;j<n;++j){
			int trans=0;
			for (int k=list[i][0];k;--k)
				if (!p[j][list[i][k]])
					trans|=1<<(list[i][0]-k);
			for (int k=m;k>=0;--k)
				if (min[k|trans]>min[k]+cost[j])
					min[k|trans]=min[k]+cost[j];
		}
		if (ans>min[m])
			ans=min[m];
	}
	if (ans==INF)
		puts("-1");
	else
		printf("%d",ans);
	return 0;
}