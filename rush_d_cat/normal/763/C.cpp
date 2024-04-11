#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
typedef long long LL;
int m,n,a[N];
LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%m;
	return t*t%m*a%m;
}
int getD(int a[],int n) {
	unordered_map<int,int> mp;
	int x=a[2]-a[1]; //x=kd
	for(int i=1;i<=n;i++){
		mp[a[i]]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(mp[(1LL*a[i]+x+m)%m])cnt++;
	}
	int k=n-cnt;
	//printf("k=%d\n", k);
	int d=(x*mpow(k,m-2)%m+m)%m;
	return d;
}
void solve(int d){
	unordered_map<int,int> mp;
	for(int i=1;i<=n;i++){
		mp[a[i]]=i;
	}
	int in[N]={0};
	for(int i=1;i<=n;i++){
		if(mp[(1LL*a[i]+d+m)%m]) in[mp[(1LL*a[i]+d+m)%m]]=1;
	}
	int pos=1;
	for(int i=1;i<=n;i++)if(in[i]==0){
		pos=i;
	}
	int beg=a[pos];
	for(int i=0;i<n;i++){
		int now=(beg+1LL*i*d)%m;
		if(mp[now]==0){
			printf("-1\n");return;
		}
	}
	printf("%d %d\n", beg,d);
}
int main() {
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==1){
		printf("%d %d\n", a[1],0);return 0;
	}
	int d=1;
	if(m>=2*n)d=getD(a,n);
	else{
		int b[N]={0},vis[N]={0};
		for(int i=1;i<=n;i++) vis[a[i]]=1;
		int tot=0;
		for(int i=0;i<m;i++) if(vis[i]==0) b[++tot]=i;
		d=getD(b,tot);
		if(n==m)d=1;
	}
	//printf("d=%d\n", d);
	solve(d);
}