#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=200000+19;
const int p=1e9+7;

struct node{
	int x,y;
	bool operator < (const node &B) const{
		return x<B.x||x==B.x&&y<B.y;
	}
} P[N];
int fac[N],inv[N],f[N][25];
int n,m,k,s,x,y,b1,b2,sum,res;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}
int calc(int x,int y){
	return 1ll*fac[x+y]*inv[x]%p*inv[y]%p;
}
int work(int x){
	int res=s;
	For(i,0,x) res=res-res/2;
	return res;
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	n=IN(),m=IN(),k=IN(),s=IN();
	For(i,1,k+1){
		x=IN(),y=IN();
		if (x==1&&y==1) b1=1;
		if (x==n&&y==m) b2=1;
		P[i]=(node){x,y};
	}
	if (!b1) P[++k]=(node){1,1};b1^=1;
	if (!b2) P[++k]=(node){n,m};b2^=1;
	sort(P+1,P+k+1);
	For(i,1,k+1){
		f[i][1]=calc(P[i].x-1,P[i].y-1);
		For(l,1,i)
			if (P[l].x<=P[i].x&&P[l].y<=P[i].y){
				f[i][1]=(f[i][1]-1ll*f[l][1]*calc(P[i].x-P[l].x,P[i].y-P[l].y)%p+p)%p;
			}
		sum=f[i][1];
		For(j,2,25){
			f[i][j]=calc(P[i].x-1,P[i].y-1);
			For(l,1,i)
				if (P[l].x<=P[i].x&&P[l].y<=P[i].y){
					f[i][j]=(f[i][j]-1ll*f[l][j]*calc(P[i].x-P[l].x,P[i].y-P[l].y)%p+p)%p;
				}
			f[i][j]=(f[i][j]-sum+p)%p;
			sum=(sum+f[i][j])%p;
		}
	}
	sum=calc(n-1,m-1);
	For(i,b1+b2,25){
		res=(res+1ll*f[k][i]*work(i-b1-b2))%p;
		sum=(sum-f[k][i]+p)%p;
	}
	res=(res+sum)%p;
	res=1ll*res*Pow(calc(n-1,m-1),p-2)%p;
	printf("%d\n",res);
}