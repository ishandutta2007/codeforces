#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 210000
int a,b;
const LL inf=(LL)1e15;
inline LL Max(int x,int y){
	if(x>y)return -inf;
	return (y-x+1)*1ll*(y-x+1)+x-1;
}
inline LL Min(int x,int y){
	if(x>y)return inf;
	int Ba=y/x;
	int Nu=y%x;
	return Nu*1ll*(Ba+1)*1ll*(Ba+1)+(x-Nu)*1ll*Ba*Ba;
}
struct sel{
	int da,db;
	inline sel(int x=0,int y=0){da=x;db=y;}
	inline LL cost(){
		if(da==-1)return -inf;
		return Max(da,a)-Min(db,b);
	}
	inline void out(){
		if(da==db){
			int Ba=b/db;
			int Nu=b%db;
			rep(i,1,da){
				if(i==1){
					rep(j,1,a-da+1)printf("o");
				}
				else printf("o");
				rep(j,1,Ba+(i<=Nu))printf("x");
			}
		}
		if(da==db+1){
			int Ba=b/db;
			int Nu=b%db;
			rep(i,1,db){
				if(i==1){
					rep(j,1,a-da+1)printf("o");
				}
				else printf("o");
				rep(j,1,Ba+(i<=Nu))printf("x");
			}
			printf("o");
		}
		if(da==db-1){
			int Ba=b/db;
			int Nu=b%db;
			rep(i,1,da){
				rep(j,1,Ba+(i<=Nu))printf("x");
				if(i==1){
					rep(j,1,a-da+1)printf("o");
				}
				else printf("o");
			}
			rep(j,1,Ba)printf("x");
		}
	}
}Ans;
inline bool operator >(sel x,sel y){return x.cost()>y.cost();}
inline void tepan(){
	if(!a){
		printf("%I64d\n",-b*1ll*b);
		rep(i,1,b)printf("x");
	}
	else
	{
		printf("%I64d\n",a*1ll*a);
		rep(i,1,a)printf("o");
	}
	exit(0);
}
int main(){
	scanf("%d%d",&a,&b);Ans=sel(-1,-1);
	if(a*b==0)tepan();
	rep(i,1,a){
		if(i-1>0){
		sel u=sel(i,i-1);
		if(u>Ans)Ans=u;
		}
		sel u=sel(i,i);
		if(u>Ans)Ans=u;
		u=sel(i,i+1);
		if(u>Ans)Ans=u;
	}
	printf("%I64d\n",Ans.cost());
	Ans.out();
	return 0;
}