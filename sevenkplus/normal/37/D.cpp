#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 110
#define M 1010
#define P 1000000007
int n, a[N], b[N];
int F[M], IF[M];
int f[N][M];

void gcd(int a,int b,int &x,int &y) {
  if(b==0){x=1,y=0;return;}
  gcd(b,a%b,y,x),y-=a/b*x;
}
int inv(int n) {
  int x,y;gcd(n,P,x,y);
  if(x<0)x+=P;return x;
}

int C(int n, int k) {
	return (ll)F[n]*IF[k]%P*IF[n-k]%P;
}

int main() {
	F[0]=1;for(int i=1;i<M;i++)F[i]=(ll)F[i-1]*i%P;
	IF[M-1]=inv(F[M-1]);for(int i=M-1;i;i--)IF[i-1]=(ll)IF[i]*i%P;

	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) cin >> b[i];
	f[0][0] = 1;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < M; j ++) if (f[i][j]) {
			for (int k = 0; k <= min(b[i], j+a[i]); k ++) {
				(f[i+1][j+a[i]-k] += (ll)f[i][j]*C(j+a[i], k)%P) %= P;
			}
		}

	int S = f[n][0];
	S = (ll)S*F[accumulate(a, a+n, 0)]%P;
	for (int i = 0; i < n; i ++) {
		S = (ll)S*IF[a[i]]%P;
	}
	cout << S << endl;
	return 0;
}