#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define x first
#define y second
#define pb push_back

int power(int a, int b, int c, int ans=1) {
	for (; b; b>>=1, a=(INT)a*a%c) if (b&1) ans=(INT)ans*a%c;
	return ans;
}

const int NN = 500010;

int a[NN], s[NN], b[NN];
pii p[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int n, nn=0;
	cin>>n;
	for (int i=0; i<n; i++) scanf("%d", a+i);
	sort(a, a+n);
	for (int i=0, j; i<n; i=j) {
		for (j=i; j<n && a[i]==a[j]; j++);
		p[nn++]=pii(j-i, a[i]);
	}
	sort(p, p+nn);
	for (int i=0; i<nn; i++) s[i]=p[i].x+(i?s[i-1]:0);
	int ans = 0, L;
	for (int i=1; i*i<=n; i++) {
		int u=lower_bound(p, p+nn, pii(i, 0))-p;
		int m=((u?s[u-1]:0)+(nn-u)*i)/i*i;
		if (m/i<i) continue;
		if (ans<m) {
			ans=m;
			L=i;
		}
	}

	cout<<ans<<endl;
	cout<<L<<' '<<ans/L<<endl;
	for (int i=0; i<nn; i++) p[i].x=min(p[i].x, L);
	reverse(p, p+nn);
	for (int k=0, j=0, R=ans/L; j<R; j++) {
		for (int i=0; i<L; i++) {
			if (p[k].x==0) k++;
			int u=p[k].y; p[k].x--;
			b[i*R+(j+i)%R]=u;
		}
	}
	for (int i=0; i<L; i++) {
		for (int j=0, R=ans/L; j<R; j++) {
			if (j) putchar(' ');
			printf("%d", b[i*R+j]);
		}
		puts("");
	}

	return 0;
}