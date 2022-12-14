#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N=200005;
int n,k,q,B,a[2][N],c[N],d[N],tot,pos[N],ed[N],tag[N],ref,lastans[N],ans,cnt[450][1<<15|1];
bool nosol[N];

void update(int l,int r,int v) {
	for (int i=l;i<=min(r,l/B*B+B-1);i++)
		cnt[l/B][d[i]]--,cnt[l/B][d[i]^=v]++;
	if (l/B!=r/B) {
		for (int i=r/B*B;i<=r;i++)
			cnt[r/B][d[i]]--,cnt[r/B][d[i]^=v]++;
		for (int i=l/B+1;i<r/B;i++)
			tag[i]^=v;
	}
}
int query(int l,int r) {
	int ans=r-l+1;
	for (int i=l;i<=min(r,l/B*B+B-1);i++)
		ans-=((d[i]^tag[l/B])==0);
	if (l/B!=r/B) {
		for (int i=r/B*B;i<=r;i++)
			ans-=((d[i]^tag[r/B])==0);
		for (int i=l/B+1;i<r/B;i++)
			ans-=cnt[i][tag[i]];
	}
	return ans;
}

void recalc(int x) {
	ans-=lastans[x];
	ref-=nosol[x];
	ans+=(lastans[x]=query((x==0?-1:ed[x-1])+1,ed[x]));
	ref+=(nosol[x]=((tag[ed[x]/B]^d[ed[x]])!=0));
}
void modify(int i,int v) {
	c[i]^=v;
	update(pos[i],ed[i%k],v);
	recalc(i%k);
}

int main() {
	scanf("%d%d%d",&n,&k,&q);
	B=(int)sqrt(n)+1;
	for (int i=1;i<=n;i++) scanf("%d",a[0]+i);
	for (int i=1;i<=n;i++) scanf("%d",a[1]+i),c[i]=a[0][i]^a[1][i];
	for (int i=0;i<=n;i++) c[i]^=c[i+1];
	for (int i=0;i<k;i++)
		for (int j=0,sum=0;j*k+i<=n;j++)
			d[tot]=(sum^=c[j*k+i]),cnt[tot/B][d[tot]]++,pos[j*k+i]=ed[i]=tot++;
	for (int i=0;i<k;i++)
		recalc(i);
	printf("%d\n",ref?-1:ans);
	while (q--) {
		int id,p,v;
		char op;
		scanf(" %c%d%d",&op,&p,&v);
		id=(op=='b');
		modify(p-1,v^a[id][p]),modify(p,v^a[id][p]);
		a[id][p]=v;
		printf("%d\n",ref?-1:ans);
	}
}