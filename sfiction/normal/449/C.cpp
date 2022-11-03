/*
ID: Sfiction
OJ: CF
PROB: 499C
*/
#include <cstdio>
#include <cstring>

const int MAXN=1E5+100;

bool use[MAXN];
int cnt,prime[MAXN];

int ans,list[MAXN][2];

void pre(){
	static bool p[MAXN];
	int i,j;

	memset(p,0,sizeof(p));
	cnt=0;
	for (i=2;i*i<MAXN;++i){
		if (!p[i])
			prime[cnt++]=i;
		for (int j=i*i;j<MAXN;j+=i)
			p[j]=true;
	}
	for (;i<MAXN;++i)
		if (!p[i])
			prime[cnt++]=i;
}

int main(){
	pre();
	int n,r;

	scanf("%d",&n);
	for (r=0;prime[r]<=n/2;++r);
	--r;
	memset(use,0,sizeof(use));
	for (int i=r;i>=0;--i){
		int sum=0,u=prime[i];
		for (int j=n/u*u;j>2*u;j-=u)
			if (!use[j]){
				list[ans][sum&1]=j;
				ans+=sum&1;
				++sum;
				use[j]=true;
			}
		if (!(sum&1)){
			list[ans][0]=u<<1;
			use[u<<1]=true;
		}
		list[ans++][1]=u;
		use[u]=true;
	}
	printf("%d\n",ans);
	for (int i=0;i<ans;++i)
		printf("%d %d\n",list[i][0],list[i][1]);
	return 0;
}