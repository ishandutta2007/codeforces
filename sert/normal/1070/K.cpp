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

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100;

int n, k;

int a[maxn];

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
    cin >> n >> k;
    int all = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], all += a[i];
    if (all % k != 0){
        cout << "No";
        return 0;
    }
    int s = all / k;
    vector<int> ans;
    int v = 0;
    int w = 0;
    for (int i = 0; i < n; i++){
        v += a[i];
        w++;
        if (v == s){
            v = 0;
            ans.push_back(w);
            w = 0;
        } else
        if (v > s) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i : ans)
        cout << i << ' ';
}