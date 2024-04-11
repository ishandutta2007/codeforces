#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<INT, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

const int NN = 2000111;
char a[NN], b[NN], s[NN];
INT tot;
int n, m;
char tmp[NN];
int nxt[NN], pre[NN];
INT res;
pii B[NN];
pii C[NN];
pii D[NN];

inline void update(pii *B, int u) {
	int d=u;
	while(u) B[u].y++, B[u].x+=d, u-=u&-u;
}

inline INT calc(pii *B, int u, INT ans=0) {
	INT d = u;
	while(u<NN) ans += B[u].x, ans -= B[u].y * (d-1), u += u&-u;
	return ans;
}

void func(int n, char *t, int *z){
	z[0]=0;
	for(int i=1, l=0, r=0; i<n; i++){
		if(i<=r) z[i]=min(z[i-l], r-i+1);
		else z[i]=0;
		while(i+z[i]<n && t[i+z[i]]==t[z[i]]) z[i]++;
		if(i+z[i]-1>r) l=i, r=i+z[i]-1;
	}
}

inline void rev(char *s, int n) {
	reverse(s, s+n);
}

int solve() {
	strcpy(tmp, s);
	strcat(tmp, "*");
	strcat(tmp, a);
	func(n+m+1, tmp, nxt);
	for(int i=m+1; i<n+m+1; i++) nxt[i-m-1]=nxt[i];
	rev(s, m);
	rev(b, n);
	strcpy(tmp, s);
	strcat(tmp, "*");
	strcat(tmp, b);
	func(n+m+1, tmp, pre);
	for(int i=m+1; i<n+m+1; i++) pre[i-m-1]=pre[i];
	reverse(pre, pre+n);
	for(int i=0; i<n; i++) if(pre[i]) update(C, min(m-1, pre[i]));
	rev(b, n);
	rev(s, m);
	for(int i=n-1; i>=0; i--) {
		int ed=i+m-1;
		if(ed<n) {
			update(B, min(m-1, pre[ed]));
			if(nxt[i]) {
				res += calc(B, max(m-nxt[i], 1));
			}
		}
		if(nxt[i]) tot += calc(C, max(m-nxt[i], 1));
	}
	for(int i=0; i<n; i++) {
		int ed=i-1;
		if(ed>=0) {
			update(D, min(m-1, pre[ed]));
			if(nxt[i]) res += calc(D, max(m-nxt[i], 1));
		}
	}
}

int sss() {
	cin >> n >> m;
	scanf("%s %s %s", a, b, s);
	solve();
	cout << tot - res << endl;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	sss();
	return 0;
}