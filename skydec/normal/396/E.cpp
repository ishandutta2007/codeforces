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
#define MAXN 1010000
inline void read(int &x){
	x=0;char p=getchar();
	while(!(p<='9'&&p>='0'))p=getchar();
	while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
inline void read(LL &x){
	x=0;char p=getchar();
	while(!(p<='9'&&p>='0'))p=getchar();
	while(p<='9'&&p>='0')x*=10ll,x+=p-48,p=getchar();
}
const int N=1000000;
int n;int p[MAXN];LL a[MAXN],k;int mp[MAXN];
inline void down(int x,LL wei){
	a[x]-=wei;for(x--;x!=1;x/=mp[x])a[mp[x]]+=wei;
}
inline void init(){
	rep(i,2,N)if(!mp[i]){
		rep(j,1,N/i)if(!mp[j*i])mp[i*j]=i;
	}
}
inline void BruteForce(LL TOT){
	rep(tt,1,TOT)rep(i,2,N)if(a[i])down(i,1);
}
inline void Out(){
	int m=0;
	rep(i,2,N)if(a[i])m++;
	printf("%d\n",m);
	rep(i,2,N)if(a[i])printf("%d %I64d\n",i,a[i]);
}
inline void work(){
	BruteForce(20);
	k-=20;
	per(i,N,2)if(a[i]){
		if(a[i]<=k)down(i,a[i]);
		else down(i,k);
	}
	Out();
}
int main(){
	scanf("%d",&n);rep(i,1,n){read(p[i]);read(a[p[i]]);}
	read(k);init();
	if(k<=20){BruteForce(k);Out();return 0;}
	else work();
	return 0;
}