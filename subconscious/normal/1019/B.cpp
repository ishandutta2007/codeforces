#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
int n,l,r,s,x,p;
int main(){
	scanf("%d",&n);
	int L=n/2;
	if(L&1){puts("! -1");return 0;}
	printf("? %d\n",1);
	fflush(stdout);
	scanf("%d",&x);s+=x;
	printf("? %d\n",1+L);
	fflush(stdout);
	scanf("%d",&x);s-=x;
	if(s==0){puts("! 1");return 0;}
	int l=2,r=L;
	while(l<r){
		int mid=(l+r)/2;p=0;
		printf("? %d\n",mid);
		fflush(stdout);
		scanf("%d",&x);p+=x;
		printf("? %d\n",mid+L);
		fflush(stdout);
		scanf("%d",&x);p-=x;
		if(p==0){printf("! %d\n",mid);return 0;}
		if((p<0)^(s<0))r=mid-1;else l=mid+1;
	}
	printf("! %d\n",l);
	return 0;
}