#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
struct node{
	LL v;
	int id,day;
}b[200003];

int n,m,k,s,a[200003][2],f[3],t[200003],cost[200003];

bool cmp(node x,node y){
	return x.v<y.v;
}

bool check(int mid){
	f[1]=f[2]=1;
	for(int i=2;i<=mid;i++) {
		if (a[i][1]<a[f[1]][1])  f[1]=i;
		if (a[i][2]<a[f[2]][2]) f[2]=i;
	}
	for(int i=1;i<=m;i++) b[i]=node{ (LL)a[ f[t[i]]][t[i]]*cost[i],i,f[t[i]] };
    sort(b+1,b+m+1,cmp);
    LL ret=0;
    for (int i=1;i<=k;i++) ret+=b[i].v;
	return ret<=s;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;i++) scanf("%d",&a[i][1]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i][2]);
	for(int i=1;i<=m;i++) scanf("%d%d",&t[i],&cost[i]);
	int l=1,r=n+1;
	while (l<r) {
		int mid=(l+r) >>1;
		if ( check(mid)) r=mid;
			else l=mid+1;
	}
	if (l>n) puts("-1");
	else {
		printf("%d\n",l);
		check(l);
		for(int i=1;i<=k;i++) printf("%d %d\n",b[i].id,b[i].day);
	}
	return 0;
}