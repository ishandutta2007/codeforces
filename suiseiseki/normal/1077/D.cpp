#include <cstdio>
#include <algorithm>
using namespace std;
struct Number{
	int id;
	int num;
	friend bool operator <(Number p,Number q){
		return p.num>q.num;
	}
}a[200005];
int n,k;
bool check(int x){
	long long ans=0;
	for(int i=1;i<=200000;i++){
		ans+=a[i].num/x;
	}
	return ans>=k;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d",&n,&k);
	int x;
	for(int i=1;i<=200000;i++){
		a[i].id=i;
		a[i].num=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x].num++;
	}
	sort(a+1,a+1+200000);
	int left=1,right=200000;
	int mid;
	while(left<right){
		mid=(left+right+1)>>1;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	int now;
	long long use=0;
	for(int i=1;i<=200000;i++){
		if(use+a[i].num/left>=k){
			now=k-use;
			while(now--){
				printf("%d ",a[i].id);
			}
			break;
		}
		use+=a[i].num/left;
		now=a[i].num/left;
		while(now--){
			printf("%d ",a[i].id);
		}
	}
	puts("");
	return 0;
}