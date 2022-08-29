#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
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
typedef set<int>::iterator it;
const int MAXN=110000;
const int jsb=1000000007;
struct rzz{
	int size,l,r,val,sum;
	rzz(int _size=0,int _l=0,int _r=0,int _val=0,int _sum=0){
		size=_size;l=_l;r=_r;val=_val;sum=_sum;
	}
};
inline rzz operator +(const rzz &a,const rzz &b){
	return rzz((a.size+b.size)%jsb,a.l,b.r,(a.val*1ll+b.val*1ll+a.r*1ll*b.l)%jsb,(a.sum+b.sum)%jsb);
};
inline rzz operator +(const rzz &a,const int &b){
	rzz res=a;
	res.val=(res.val+b*1ll*((a.sum*2ll-a.l-a.r)%jsb)%jsb)%jsb;
	res.val=(res.val+((res.size-1)*1ll*b%jsb)*1ll*b%jsb)%jsb;
	res.l=(res.l+b)%jsb;
	res.r=(res.r+b)%jsb;
	res.sum=(res.sum+(res.size)*1ll*b%jsb)%jsb;
	return res;
}
rzz f[MAXN];//4444....444  ~7777...7777
rzz g[MAXN];//4 ~ 7777...7777
int po4[MAXN];//4*10^n
int po7[MAXN];//7*10^n
int n;
char a[MAXN],b[MAXN];
inline void init(){
	f[1]=rzz(2,4,7,28,11);
	g[1]=rzz(2,4,7,28,11);
	po4[1]=4;po7[1]=7;
	rep(i,2,n){
		po4[i]=po4[i-1]*10ll%jsb;
		po7[i]=po7[i-1]*10ll%jsb;
	}
	rep(i,2,n){
		f[i]=(f[i-1]+po4[i])+(f[i-1]+po7[i]);
		g[i]=g[i-1]+f[i];
	}
}
rzz gt[MAXN];
rzz work(){
	rzz now;
	rep(i,1,n)a[i]-='0';
	if(a[n]==4)gt[n]=rzz(1,4,4,0,4);
	else gt[n]=rzz(2,4,7,28,11);
	//gt[i]:  44444...44 ~ a[i..n]
	//the lastans:g[n-1]+gt[n]
	per(i,n-1,1){
		if(a[i]==4){
			gt[i]=gt[i+1]+po4[n-i+1];
		}
		else{
			gt[i]=(f[n-i]+po4[n-i+1])+(gt[i+1]+po7[n-i+1]);
		}
	}
	return g[n-1]+gt[1];
}
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	if(n==1){
		printf("28\n");
		return 0;
	}
	init();
	rzz a1=work();
	rep(i,1,n)a[i]=b[i];
	rzz a2=work();
	int res=a2.val-a1.val;
	res%=jsb;
	if(res<0)res+=jsb;
	printf("%d\n",res);
	return 0;
}