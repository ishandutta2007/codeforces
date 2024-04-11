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
typedef double db;bool fuck=0;
struct huge{
	int a[1010000];
	inline void init(int x){
		a[1]=x;
		a[0]=1;
	}
	inline void operator -=(const int &x){
		a[1]-=x;
		rep(i,1,a[0])if(a[i]<0){
			a[i]+=10;
			a[i+1]--;
		}
		while(!a[a[0]]&&a[0])a[0]--;
	}
	inline void operator /=(const int &x){
		fuck=0;
		per(i,a[0],1){
			if(i==1&&a[i]%x!=0){fuck=1;return;}
			a[i-1]+=10*(a[i]%x);
			a[i]/=x;
		}
		fuck=0;
		while(!a[a[0]]&&a[0])a[0]--;
	}
	void print(){
		per(i,a[0],1)printf("%d",a[i]);
	}
}a;
int p,x;
int main(){
	scanf("%d%d",&p,&x);x=10*x-1;
	rep(i,1,9){
		memset(a.a,0,sizeof a.a);
		a.a[0]=p+1;
		a.a[a.a[0]]=i;
		a-=i;a/=x;
		if(fuck)continue;
		if(a.a[0]!=p)continue;
		a.print();
		return 0;
	}
	printf("Impossible");
	return 0;
}