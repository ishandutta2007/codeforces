#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+5;
int n,m;
int s[100],cur;
int t[100];
int main(){
	scanf("%d%d",&m,&n);
	cur=0;
	rep(i,n){
		printf("%d\n",1);
		fflush(stdout);++cur;
		scanf("%d",&s[cur]);
		if(s[cur]==0)return 0;
	}
	rep(i,n)t[i]=(s[i]==1);
	int l=2,r=m;
	while(l<=r){
		int mid=(l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);++cur;
		scanf("%d",&s[cur]);
		if(s[cur]==0)return 0;
		if((s[cur]==1)^(t[(cur-1)%n+1]==1))r=mid-1;else l=mid+1;
	}
	return 0;
}