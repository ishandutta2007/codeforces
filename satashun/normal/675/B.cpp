#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
int ret;
int a, b, c, d;

bool in(int x)
{
    return x >= 1 && x <= n;
}

int main() {
    cin >> n >> a >> b >> c >> d;

    for (int i = 1; i <= n; ++i) {
	int u = i + b - c;
	int v = i + d - a;
	int l = i + b - c + d - a;
	if (in(u) && in(v) && in(l)) ++ret;
    }

    cout << (ll)ret * n << endl;

    return 0;
}