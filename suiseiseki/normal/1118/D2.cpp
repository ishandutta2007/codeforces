#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define ll long long
int a[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int n,m;
int mx(int a,int b){
	return a>b?a:b;
}
bool check(int x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=mx(0,a[i]-(i-1)/x);
	}
	return sum>=m;
}
int main(){
	scanf("%d%d",&n,&m);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum<m){
		puts("-1");
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int left=1,right=n,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
	return 0;
}