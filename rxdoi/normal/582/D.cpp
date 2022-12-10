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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=4000+19;
const int p=1e9+7;

int d[N],f[N][N][2][2];
int P,alpha,res,tmp;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}
void U(int &x,ll y) {x=(x+y)%p;}
int S(int x,int y){
	return 1ll*(x+y)*(y-x+1)/2%p;
}

struct Bigint{
	int len;
	ll s[N];
	void Clear(){
		while (len>1&&!s[len-1]) len--;
	}
	void operator /= (const int &b){
		for (int i=len-1;~i;i--){
			if (i) s[i-1]+=s[i]%b*10;
			s[i]/=b;
		}
		Clear();
	}
	void IN(){
		static char c[N];
		scanf("%s",c);
		len=strlen(c);
		For(i,0,len) s[i]=c[i]-'0';
		reverse(s,s+len);
	}
} A;

int operator % (const Bigint &A,int b){
	int tmp=0;
	for (int i=A.len-1;~i;i--) tmp=(tmp*10ll+A.s[i])%b;
	return tmp;
}

int main(){
	P=IN(),alpha=IN();
	A.IN();
	while (!(A.len==1&&A.s[0]==0)) d[++*d]=A%P,A/=P;
	reverse(d+1,d+*d+1);
	if (alpha>*d){
		puts("0");
		return 0;
	}
	f[*d+1][0][1][1]=1;
	for (int i=*d;i;i--){
		For(j,0,*d+1) For(x,0,2) For(y,0,2)
			if (tmp=f[i+1][j][x][y]){
//				For(n,0,P) For(k,0,P){
//					U(f[i][j+!(k<n||k==n&&y)][n<d[i]||n==d[i]&&x][k<n||k==n&&y],f[i+1][j][x][y]);
//				}
				if (x==0){
					if (y==0){
						U(f[i][j][0][1],	1ll*S(d[i],P-1)*tmp);
						U(f[i][j+1][0][0],	1ll*S(1,P-d[i])*tmp);
						U(f[i][j][1][1],	1ll*S(0,d[i]-1)*tmp);
						U(f[i][j+1][1][0],	1ll*S(P-d[i]+1,P)*tmp);
					} else{
						U(f[i][j][1][1],	1ll*S(1,d[i])*tmp);
						U(f[i][j+1][1][0],	1ll*S(P-d[i],P-1)*tmp);	
						U(f[i][j][0][1],	1ll*S(d[i]+1,P)*tmp);
						U(f[i][j+1][0][0],	1ll*S(0,P-d[i]-1)*tmp);
					}
				} else{
					if (y==0){
						U(f[i][j][0][1],	1ll*S(d[i]+1,P-1)*tmp);
						U(f[i][j+1][0][0],	1ll*S(1,P-d[i]-1)*tmp);
						U(f[i][j][1][1],	1ll*S(0,d[i])*tmp);
						U(f[i][j+1][1][0],	1ll*S(P-d[i],P)*tmp);
					} else{
						U(f[i][j][0][1],	1ll*S(d[i]+2,P)*tmp);
						U(f[i][j+1][0][0],	1ll*S(0,P-d[i]-2)*tmp);
						U(f[i][j][1][1],	1ll*S(1,d[i]+1)*tmp);
						U(f[i][j+1][1][0],	1ll*S(P-d[i]-1,P-1)*tmp);
					}
				}
			}
	}
	For(i,alpha,*d+1){
		U(res,f[1][i][1][1]);
	}
	printf("%d\n",res);
}