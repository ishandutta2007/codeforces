#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int calc(int x){
	int ans=0;
	while(x){
		ans+=(x%10);
		x/=10;
	}
	return ans;
}
int q[1010000];
int main(){
	int n;scanf("%d",&n);
	per(sum,9*9,0)if(n>=sum)if(calc(n-sum)==sum){
		q[++q[0]]=n-sum;
	}
	printf("%d\n",q[0]);
	rep(i,1,q[0])printf("%d ",q[i]);
	return 0;
}