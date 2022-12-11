#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

LL n;
int q;

int main(){
	scanf("%I64d%d",&n,&q);
	fo(cas,1,q){
		LL x;
		scanf("%I64d",&x);
		LL ans=0;
		for(LL now=n;now;now/=2){
			if (x&1){ans=ans+(x+1)/2;break;}
			if ((now&1)==0){
				ans=ans+now/2;
				x=x/2;
			}
			else{
				ans=ans+(now+1)/2;
				x=x/2;
				x=x-1;
				if(x==0)x=now/2;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}