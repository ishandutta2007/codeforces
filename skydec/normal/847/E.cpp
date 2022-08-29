#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
char a[N];int n;
bool check(int S){
	int pre=0;
	int now=0;
	rep(i,1,n)if(a[i]=='*'){
		if(i>now&&(!pre))pre=i;
	}
	else if(a[i]=='P'){
		if(!pre)pre=i;
		if(i-pre>S)return 0;
		now=max(now,min(n,S+2*pre-i));
		now=max(now,min(n,(S+i+pre)/2));
		pre=0;
	}
	return (!pre);
}
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	int l=1;int r=2*n;
	int ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid+1;
	}
	if(check(l))ans=l;
	printf("%d\n",ans);
	return 0;
}