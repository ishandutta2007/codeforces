#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long a[100000],b[100000];
int n,m;
bool check(long long lim){
	int j=0;
	for(int i=0;i<n;i++){
		if(j>=m)break;
		long long res;
		if(a[i]<b[j]){
			int k=lower_bound(b,b+m,a[i]+lim)-b;
			if(b[k]==a[i]+lim)k++;
			if(k>j)j=k;
		}else{
			res=lim-(a[i]-b[j]);
			if(res<0)continue;
			res=max(res/2,b[j]-a[i]+res);
			int k=lower_bound(b,b+m,a[i]+res)-b;
			if(b[k]==a[i]+res)k++;
			if(k>j)j=k;
		}
	}
	if(j>=m)return 1;else return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	for(int j=0;j<m;j++)
		scanf("%I64d",&b[j]);
	long long h=0,t=max(a[0]-b[0],b[0]-a[0])+b[m-1]-b[0];
	while(h<t){
		long long m=(h+t)/2;
		if(check(m))t=m;else h=m+1;
	}
	printf("%I64d\n",h);
	return 0;
}