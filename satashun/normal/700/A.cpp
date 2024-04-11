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

int n, k;
double l, v1, v2;

int main() {
    cin >> n >> l >> v1 >> v2 >> k;

    double lb = l / v2, ub = l / v1;

    int num = (n + k - 1) / k;

    rep(tt, 200) {
	double m = (lb + ub) / 2;

	double ns = (l - m * v1) / (v2 - v1);

	if (ns * num + ns * (v2 - v1) / (v2 + v1) * (num - 1) <= m) ub = m;
	else lb = m;
    }

    printf("%.8f\n", lb);

    return 0;
}