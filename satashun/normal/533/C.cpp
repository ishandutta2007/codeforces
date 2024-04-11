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

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    int s = a + b;
    int t = max(c, d);

    if (s <= t || (a <= c && b <= d)) {
	puts("Polycarp");
    } else puts("Vasiliy");

    return 0;
}