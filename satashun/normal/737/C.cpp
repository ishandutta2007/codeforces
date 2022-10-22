#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, s;
int a[200010];
int num[200010];
int ac[200010];
int n0;
int f;

int main() {
	scanf("%d %d", &n, &s); --s;

	rep(i, n) {
		scanf("%d", &a[i]);

		if (i == s) {
			if (a[i] != 0) f = 1;
		} else {
			if (a[i] == 0) {
				++n0;
			} else ++num[a[i]];
		}
	}

	if (n == 1) {
		cout << f << endl;
		return 0;
	}

	ac[0] = 1;

	for (int i = 1; i <= n; ++i) {
		ac[i] = ac[i-1] + (num[i] ? 1 : 0);
		num[i] += num[i-1];
	}

	int u = n;

	for (int t = 1; t < n; ++t) {
		int mt = ac[t];
		//cout<<mt<<endl;
		int zan = num[n] - num[t] + n0;
		//cout<<"zan "<<zan<<endl;

		//printf("DEB %d: %d\n", t, max(t+1-mt, zan) + f);
		u = min(u, max(t+1-mt, zan));
	}

	printf("%d\n", u + f);

	return 0;
}