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

ll n, a, b, p, q, c;
ll ret;

int main() {
    cin >> n >> a >> b >> p >> q;

    c = __gcd(a, b);
    c = a / c * b;

    ret = max(p * (n / a - n / c) + q * (n / b), q * (n / b - n / c) + p * (n / a));
    cout << ret << endl;

    return 0;
}