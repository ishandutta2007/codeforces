#include <cstdio>
#include <algorithm>
using namespace std;
int num[105];
int a[105];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	sort(num+1,num+101,cmp);
	int ans=0;
	int now=0;
	for(int i=1;i<=100;i++){
		if(num[i]==0){
			break;
		}
		now=max(now,(num[i]+k-1)/k*k);
	}
	for(int i=1;i<=100;i++){
		if(num[i]==0){
			break;
		}
		ans+=now-num[i];
	}
	printf("%d\n",ans);
	return 0;
}