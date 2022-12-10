#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2e5+19;

map<ll,ll> A,B;
ll x[N],y[N],z[N],sum,ga,gb;
int n,ans;

int main(){
	n=IN();
	For(i,1,n+1){
		x[i]=IN(),y[i]=IN(),z[i]=IN();
		A[x[i]]+=z[i];
		B[y[i]]+=z[i];
		sum+=z[i];
	}
	For(i,1,n+1){
		if (fabs(db(1.0)*sum*z[i]-db(1.0)*A[x[i]]*B[y[i]])>1){
			puts("0");
			return 0;
		}
	}
	for (auto P:A) ga=__gcd(ga,P.se);
	for (auto P:B) gb=__gcd(gb,P.se);
	for (int i=1;1ll*i*i<=ga;i++)
		if (ga%i==0){
			if (sum%i==0&&gb%(sum/i)==0) ans++;
			if (1ll*i*i!=ga){
				if (sum%(ga/i)==0&&gb%(sum/(ga/i))==0) ans++;
			}
		}
//	if (n==9420) printf("%lld %lld %lld\n",ga,gb,sum);
	printf("%d\n",ans);
}