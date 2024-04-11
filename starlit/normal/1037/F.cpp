#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000006
#define M 1000000007
using namespace std;
int n,x,y,k,a[N],no[N],le[N],rt[N],
sum[N<<1];
long long ans,ss;
bool cmp(int x,int y){
	return a[x]^a[y]?a[x]<a[y]:x<y;
}
inline void cal(int s,int x,int e,int v){
	ss+=v*(sum[e-s]-sum[e-x-1]);
}
int main(){
	scanf("%d%d",&n,&k),k--;
	for(int i=1;i<=n+k;i++)
	sum[i]=(sum[i-1]+i/k)%M;
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),no[i]=i;
	sort(no+1,no+n+1,cmp);
	for(int i=1;i<=n;i++){
		x=no[i];
		le[x]=rt[x]=x;
		if(x>1&&a[x-1]<=a[x])
		le[x]=le[x-1];
		if(x<n&&a[x+1]<a[x])
		rt[x]=rt[x+1];
		le[rt[x]]=le[x],rt[le[x]]=rt[x];
		ss=x-le[x];
		cal(le[x],x,rt[x],1),cal(le[x],x,x+k-1,-1);
		//cerr<<le[x]<<'-'<<x<<'-'<<rt[x]<<':'<<ss<<endl;
		ans+=ss%M*a[x]%M;
	}
	printf("%d",(ans%M+M)%M);
}