#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=805;
const int P=1000000007;
int inv10;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
char a[N];
int n;
int p10[N*10];
int cnt[15];
int S[N];
int fac[N],inv[N];
int f1[12][N];
int f2[12][N];
void init(){
	rep(i,1,9)rep(m,0,n){
		rep(k,0,m){
			int w=Pow(9-i,m-k)*1ll*inv[k]%P;
			w=w*1ll*inv[m-k]%P;
			f2[i][m]=(f2[i][m]+w)%P;
			w=w*1ll*p10[k]%P;
			f1[i][m]=(f1[i][m]+w)%P;
		}
	}
}
int calc(int n){
	S[0]=cnt[0];
	rep(i,1,9)S[i]=S[i-1]+cnt[i];

	int ans=0;
	rep(i,1,9){
		int w=i;
		w=w*1ll*inv10%P;
		w=w*1ll*Pow(inv10+P-1,P-2)%P;
		int t=1;
		rep(j,0,n){
			int s=p10[j+S[i-1]];
			s=s*1ll*t%P;
			t=t*1ll*i%P;
			s=s*1ll*inv[j]%P;
			int d=f1[i][n-j]*1ll*p10[cnt[i]]%P;
			d=(d+P-f2[i][n-j])%P;
			s=s*1ll*d%P;
			ans=(ans+s*1ll*w)%P;
		}
	}
	ans=ans*1ll*fac[n]%P;
	return ans;
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	//rep(i,1,n)a[i]='9';
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	inv10=Pow(10,P-2);
	inv[n]=Pow(fac[n],P-2);per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
	p10[0]=1;rep(i,1,N*10-2)p10[i]=p10[i-1]*1ll*inv10%P;
	rep(i,1,n)a[i]-='0';
	int ans=0;
	init();
	rep(i,0,n-1){
		rep(j,0,9)if(j<a[i+1]){
			memset(cnt,0,sizeof cnt);
			rep(k,1,i)cnt[a[k]]++;
			cnt[j]++;
			ans=(ans+calc(n-i-1))%P;
		}
	}
	ans=ans*1ll*Pow(10,n)%P;
	sort(a+1,a+1+n);
	int w=0;
	rep(i,1,n){
		w=w*10ll%P;
		w=(w+a[i])%P;
	}
	printf("%d\n",(ans+w)%P);
	return 0;
}