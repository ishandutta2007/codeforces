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

int n;
int a[110], b[110];
map<int, int> gr;

int calc(int bit)
{
	if (gr.count(bit)) return gr[bit];
	if (bit == 0) return gr[bit] = 0;
	set<int> st;
	for (int i = 0; i <= 30; ++i) {
		if ((bit >> i) == 0) break;
		int nb = (bit >> (i+1)) | (bit & ((1 << i) - 1));
		st.insert(calc(nb)); 
	}
	int i = 0;
	while (st.count(i)) ++i;
	return gr[bit] = i;
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	vi pr;

	rep(i, n) {
		b[i] = a[i];
		for (int j = 2; j * j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				pr.pb(j);
				while (a[i] % j == 0) {
					a[i] /= j;
				}
			}
		}
		if (a[i] != 1) pr.pb(a[i]);
	}

	sort(ALL(pr));
	pr.erase(unique(ALL(pr)), pr.end());


	int xo = 0;
	for (int p : pr) {
		int bit = 0;
		rep(i, n) {
			int j = 0;
			while (b[i] % p == 0) {
				b[i] /= p;
				++j;
			}
			if (j) {
				bit |= (1 << (j-1));
			}
		}
		xo ^= calc(bit);
	}
	puts(xo ? "Mojtaba" : "Arpa");
	return 0;
}