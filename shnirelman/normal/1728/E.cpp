#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 3e5 + 13;
const int A = 26;
const int B = 400;

int gcd(int a, int b, int& x, int& y) {
	if(a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	int x1, y1;
	int d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;

	return d;
}

int a[N], b[N], c[N];
li pref[N];

/*
3
5 10
100 50
2 2
1
1 1

10
3 1
2 3
1 1
2 1
6 3
1 4
4 3
1 3
5 3
5 4
1
1 4
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
//        c[i] = b[i] - a[i];
        c[i] = a[i] - b[i];
        sum += b[i];
    }

    sort(c, c + n);
    reverse(c, c + n);

    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + c[i];
    }
//
//    cout << sum << endl;
//    for(int i = 0; i <= n; i++)
//        cout << pref[i] << ' ';
//    cout << endl;
//    for(int i = 0; i < n; i++)
//        cout << c[i] << ' ';
//    cout << endl;

    c[n] = -INF;

    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(c[i] >= 0)
            ind++;
        else
            break;
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        int kx, ky;
        int g = gcd(x, y, kx, ky);





        if(n % g != 0/* || kx < 0 || ky < 0*/) {
            cout << -1 << '\n';
            continue;
        }

        kx *= n / g;
        ky *= n / g;

        li mnk, mxk;

//        cout << g << ' ' << kx << ' ' << ky << ' ' << x * kx << ' ' << y * ky << endl;

//        if(kx < 0 || )
        {
            int l = -1e6, r = 1e6;
            while(r - l > 1) {
                int mid = (l + r) / 2;

                li kx1 = kx + mid * 1ll * y / g;
                li ky1 = ky - mid * 1ll * x / g;

//                cout << l << ' ' << mid << ' ' << r << ' ' << kx1 << ' ' << ky1 << endl;

                if(kx1 < 0)
                    l = mid;
                else
                    r = mid;
            }

            mnk = r;
        }
//cout << "afg" << endl;
        {
            int l = -1e6, r = 1e6;
            while(r - l > 1) {
                int mid = (l + r) / 2;

                li kx1 = kx + mid * 1ll * y / g;
                li ky1 = ky - mid * 1ll * x / g;

                if(ky1 < 0)
                    r = mid;
                else
                    l = mid;
            }

            mxk = l;
        }

        if(mnk > mxk) {
            cout << -1 << '\n';
            continue;
        }

//        cout << mnk << ' ' << mxk << endl;

//        li mnkx = kx + mnk * 1ll * y / g;
//        li mxkx = kx + mxk * 1ll * y / g;

        {
            int l = mnk, r = mxk + 1;
            while(r - l > 1) {
                int mid = (l + r) / 2;

                li kx1 = kx + mid * 1ll * y / g;
                li ky1 = ky - mid * 1ll * x / g;

//                cout << l << ' ' << r << ' ' << mid << ' ' << kx1 << ' ' << ky1 << ' ' << kx1 * x << ' ' << c[kx1 * x] << endl;

                if(c[kx1 * x] >= 0)
                    l = mid;
                else
                    r = mid;
            }

//            cout << "l  r "  << l << ' ' <<r << endl;

            li ans = -INF64;
            {
                li kx1 = kx + l * 1ll * y / g;
                li ky1 = ky - l * 1ll * x / g;

//                cout << kx1 << ' ' << ky1 << ' ' << x * kx1 << ' ' << y * ky1 << endl;

                if(x * kx1 + y * ky1 == n && x * kx1 <= n)
                    ans = max(ans, sum + pref[x * kx1]);
            }

            {
                li kx1 = kx + r * 1ll * y / g;
                li ky1 = ky - r * 1ll * x / g;

//                cout << kx1 << ' ' << ky1 << ' ' << x * kx1 << ' ' << y * ky1 << endl;

                if(x * kx1 + y * ky1 == n && x * kx1 <= n)
                    ans = max(ans, sum + pref[x * kx1]);
            }

            cout << ans << '\n';
        }
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}