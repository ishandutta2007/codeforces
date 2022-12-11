#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define up_bo(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()

using namespace std;

typedef long long ll;

void setmin(int &x, int y){
	x = min(x, y);
}

void setmax(int &x, int y){
	x = max(x, y);
}

void setmin(ll &x, ll y){
	x = min(x, y);
}

void setmax(ll &x, ll y){
	x = max(x, y);
}

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 993;

struct Bitset{
    vector<int> a;
    int n;
    void resize(int n_){
        n = n_;
        a.resize(n);
    }

    int get(int i){
        return i < n ? a[i] : 0;
    }

    void inc(int i, int x){
        if (x)
            a[i] = 1;
    }

    void go(int x){
        for (int i = n - 1; i >= x; i--)
            inc(i, get(i - x));
    }
};

int main() {
#ifdef MADE_BY_SERT
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#else
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(26);
        for (int i = 0; i < k; i++){
            char c;
            cin >> c;
            a[c - 'A']++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++){
            Bitset q;
            if (i == 25){
                int kek = 1;
            }
            q.resize(min(n + 1, k - a[i] + 1));
            q.inc(0, 1);
            for (int j = 0; j < 26; j++)
            if (i != j)
                q.go(a[j]);
            for (int x = 0; x <= min(n, a[i]); x++)
            if (q.get(n - x)){
                int rem = k - a[i] - (n - x);
                setmin(ans, x * max(0, m - rem));
            }
        }
        cout << ans << '\n';
    }
}