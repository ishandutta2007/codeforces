#include <cstdio>
#include <cstring>
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int a[Maxn+5];
int query(int x){
	if(a[x]!=-1){
		return a[x];
	}
	printf("? %d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	a[x]=ans;
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(a,-1,sizeof a);
	a[0]=a[n+1]=Inf;
	int left=1,right=n;
	while(left<right){
		int mid=(left+right)>>1;
		if(query(mid)<query(mid+1)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("! %d\n",left);
	fflush(stdout);
	return 0;
}