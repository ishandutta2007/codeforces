#include<bits/stdc++.h>
using namespace std;

int n,p[200005],q[200005],lg2[200005],mx[20][200005],ans;

int better(int x,int y){
	return p[x]>p[y]?x:y;
}
int query(int l,int r){
	int x=lg2[r-l+1];
	return better(mx[x][l],mx[x][r-(1<<x)+1]);
}
void solve(int l,int r){
	if(l>r)return;
	int m=query(l,r);
//	printf("%d %d %d\n",l,r,m);
	if(m-l<=r-m){
		for(int i=l;i<=m;++i)
			if(m<=q[p[m]-p[i]]&&q[p[m]-p[i]]<=r)
				++ans;
	}else{
		for(int i=m;i<=r;++i)
			if(l<=q[p[m]-p[i]]&&q[p[m]-p[i]]<=m)
				++ans;
	}
	solve(l,m-1);
	solve(m+1,r);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",p+i),mx[0][i]=i,q[p[i]]=i;
	for(int i=2;i<=n;++i)lg2[i]=lg2[i>>1]+1;
	for(int i=1;1<<i<=n;++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			mx[i][j]=better(mx[i-1][j],mx[i-1][j+(1<<i-1)]);
	solve(1,n);
	printf("%d\n",ans);
}