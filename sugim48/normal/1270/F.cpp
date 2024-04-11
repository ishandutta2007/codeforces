#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

struct dice {
	mt19937 mt;
	dice() {
		random_device rd;
		mt = mt19937(rd());
	}
	int operator()(int x) { return this->operator()(0, x - 1); }
	int operator()(int x, int y) {
		uniform_int_distribution<int> dist(x, y);
		return dist(mt);
	}
} dc;

// [0, d]  n*k  k 
int f(int d, int k, int n) {
    return max(0, d / k - n);
}

int a[100000000];

ll solve(string s) {
    int N = s.length();
    int n = sqrt(N);
    ll ans = 0;
    rep(d, n) {
        a[N] = 1;
        int x = 0;
        for (char c: s) {
            if (c == '0') x--;
            if (c == '1') x += d;
            ans += a[N + x]++;
        }
        a[N] = 0;
        x = 0;
        for (char c: s) {
            if (c == '0') x--;
            if (c == '1') x += d;
            a[N + x] = 0;
        }
    }
    vector<int> nxt(N + 1);
    nxt[N] = N + 1;
    int unko = N + 1;
    for (int i = N - 1; i >= 0; i--) {
        if (s[i] == '1') unko = i + 1;
        nxt[i] = unko;
    }
    
    rep(l, N) {
        int i = l, k = 0;
        for (;;) {
            k++;
            if (k * n > N) break;
            i = nxt[i];
            if (i == N + 1) break;
            int j = nxt[i] - 1;
            ans += f(j - l, k, n) - f(i - l - 1, k, n);
        }
    }
    return ans;
}

ll naive(string s) {
    int N = s.length();
    int ans = 0;
    rep(l, N) for (int r = l + 1; r <= N; r++) {
        int k = 0;
        for (int i = l; i < r; i++) if (s[i] == '1') k++;
        if (k > 0 && (r - l) % k == 0) ans++;
    }
    return ans;
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    // for (;;) {
    //     int N = dc(1, 100);
    //     string s(N, ' ');
    //     rep(i, N) s[i] = "01"[dc(2)];
    //     ll a = naive(s);
    //     ll b = solve(s);
    //     if (a != b) {
    //         cout << s << endl;
    //         cout << a << ' ' << b << endl;
    //         return 0;
    //     }
    // }
}