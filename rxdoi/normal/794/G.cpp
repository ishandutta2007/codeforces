#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double Db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2e6+19;
const int p=1e9+7;
const int top=1e6;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

string c,d;
int fac[N],inv[N],sum[N],vis[N],pri[N],phi[N];
int n,ca,cb,cw,da,db,dw,res,cha;

void Init(){
	phi[1]=1;
	For(i,2,top+1){
		if (!vis[i]){
			pri[++*pri]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=1;
			if (i%pri[j]==0){
				phi[pri[j]*i]=phi[i]*pri[j];
				break;
			} else{
				phi[pri[j]*i]=phi[i]*(pri[j]-1);
			}
		}
	}
	For(i,1,top+1) phi[i]=(phi[i-1]+phi[i])%p;
	For(i,1,top+1) phi[i]=(2ll*phi[i]-1+p)%p;
}
int C(int n,int m){
	if (n<m) return 0;
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
void cal(int x,int coef){
	int y=x-cha;
	if (x==0&&y==0){
		int tmp=1;
		if (c.length()!=d.length()){
			tmp=0;
		} else{
			For(i,0,c.length()){
				int s=(c[i]=='?')+(d[i]=='?');
				if (s==0&&c[i]!=d[i]) tmp=0;
				if (s==2) tmp=2*tmp%p;
			}
		}
		res=(res+1ll*tmp%p*sum[n]%p*sum[n])%p;
		int pw=2;
		For(d,1,n+1){
			res=(res+1ll*(coef-tmp+p)*pw%p*phi[n/d])%p;
			pw=2*pw%p;
		}
	}
	if (x>=0&&y<=0) return;
	if (x<0) x*=-1,y*=-1;
	int t=__gcd(x,y);
	x/=t,y/=t;
	res=(res+1ll*coef*sum[min(n/x,n/y)])%p;
}

int main(){
	Init();
	sum[0]=1;
	For(i,1,N) sum[i]=2*sum[i-1]%p;
	sum[0]=0;
	For(i,1,N) sum[i]=(sum[i-1]+sum[i])%p;
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	cin>>c>>d;
	if (c.length()<d.length()) swap(c,d);
	cha=c.length()-d.length();
	n=IN();
	For(i,0,c.length()){
		if (c[i]=='A') ca++;
		if (c[i]=='B') cb++;
		if (c[i]=='?') cw++;
	}
	For(i,0,d.length()){
		if (d[i]=='A') da++;
		if (d[i]=='B') db++;
		if (d[i]=='?') dw++;
	}
	for (int i=-dw;i<=cw;i++){
		cal(cb+cw-db-dw-i,C(cw+dw,i+dw));
	}
	printf("%d\n",res);
}