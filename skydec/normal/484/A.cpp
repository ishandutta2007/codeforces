#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#define pb push_back
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		LL l,r;scanf("%I64d%I64d",&l,&r);r++;
		LL x=0;
		for(int i=63;i>=0;i--){
			int x1=(l>>i)&1;
			int x2=(r>>i)&1;
			if(x1==x2){
				x*=2ll;x+=x1;
				}
			else
			{
				x*=2ll;x+=1;
				for(int j=i-1;j>=0;j--)x*=2ll;
				x--;
				break;
				}
			}
		printf("%I64d\n",x);
		}
	return 0;
}