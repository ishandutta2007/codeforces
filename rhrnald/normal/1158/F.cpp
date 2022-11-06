#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>
 
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;
 
const int N = 4100;
const int MOD = 998244353;
int n,m;
int x[N];
int ans[N][N];
int P[N];
int rev[N];
 
int cnt[N];
int B=1;
#define mult(x,y) (1ll*(x)*(y)%MOD)
int _rev(int x) {
	if(x==1) return 1;
	return -mult(MOD/x, _rev(MOD%x))+MOD;
}
static char buf[1 << 25]; // size : any number geq than 1024 
static int idx = 0;
static int bytes = 0;
static inline int _read() {
	if (!bytes || idx == bytes) {
		bytes = (int)fread(buf, sizeof(buf[0]), sizeof(buf), stdin);
		if(!bytes) return 0;
		idx = 0;
	}
	return buf[idx++];
}
static inline int _readInt() {
	int x = 0, s = 1;
	int c = _read();
	while (c <= 32) c = _read();
	if (c == '-') s = -1, c = _read();
	while (c > 32) x = 10 * x + (c - '0'), c = _read();
	if (s < 0) x = -x;
	return x;
}
int pt[N];
void solve() {
	int B=1<<m;
	ans[0][0]=1;
	for(int i=0; i<n; i++) {
		for(int j=n/m; j>=0; j--) {
			for(int k=B-1; k>=0; k--) {
				int temp=k|(1<<(x[i]-1));
				if(temp==B-1) ans[j+1][0]=(ans[j+1][0]+ans[j][k])%MOD;
				else ans[j][temp]=(ans[j][temp]+ans[j][k])%MOD;
			}
		}
	}
	for(int i=0; i<=n/m; i++) {
		for(int k=0; k<B; k++) pt[i]=(ans[i][k]+pt[i])%MOD;
	}
	pt[0]--;
	for(int i=0; i<=n; i++) printf("%d ", pt[i]%MOD);
}
 
int f[N][N];
void make() {
	for(int j=0; j<=n; j++) {
		int b=m;
		int pow=1;
		for(int i=1; i<=m; i++) cnt[i]=0;
		
		for(int i=j; i<n; i++) {
			if(!cnt[x[i]]) b--, cnt[x[i]]=1;
			else {
				cnt[x[i]]++;
				pow=mult(mult(pow, rev[cnt[x[i]]-1]), P[cnt[x[i]]]-1);
			}
 
			if(!b) f[i][j]=mult(pow, rev[cnt[x[i]]]);
		}
	}
}
int main(void){
	n=_readInt();
	m=_readInt();
	for(int i=0; i<n; i++) x[i]=_readInt();
	if(m<=11) {
		solve();
		return 0;
	}
	while(B<=m) B=B+B;
	P[0]=1;
	for(int i=1; i<=n; i++) P[i]=(P[i-1]+P[i-1])%MOD;
	for(int i=1; i<=n; i++) rev[i]=_rev(P[i]-1);		
 
	ans[0][n]=1;
 
	int pow=1;
	int b=m;
	for(int i=n-1; i>=0; i--) {
		if(!cnt[x[i]]) b--, cnt[x[i]]=1;
		else {
			cnt[x[i]]++;
			pow=mult(mult(pow, rev[cnt[x[i]]-1]), P[cnt[x[i]]]-1);
		}
		ans[0][i]=P[n-i];
		if(!b) ans[0][i]-=pow;
		if(ans[0][i]<0) ans[0][i]+=MOD;
	}
 
	make();
	
	int C=n/m;
	for(int p=1; p<=C; p++) {
		for(int j=0; j<n; j++) {
			ll temp=0;
			for(int i=j; i<n; i++) {
				if(!ans[p-1][i+1]) break;
				if(f[i][j])	temp+=mult(ans[p-1][i+1], f[i][j]);
			}
			ans[p][j]=temp%MOD;
		}
	}
	ans[0][0]--;
	for(int i=0; i<=n; i++) printf("%d ", ans[i][0]);//%MOD)+MOD)%MOD);
}