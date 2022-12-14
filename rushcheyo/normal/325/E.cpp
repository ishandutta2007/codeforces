#include<cstdio>
const int N=100005;
int n,a[N];
bool v[N];
int main(){
	scanf("%d",&n);
	if(n&1)return puts("-1"),0;
	for(int i=n;i;i--)
		if(v[a[i]+n>>1])v[a[i-1]=a[i]>>1]=true;
		else v[a[i-1]=a[i]+n>>1]=true;
	for(int i=0;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}