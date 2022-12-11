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

struct myhash{
    int operator() (const string &s) const{
        int h = 0;
        for (auto i : s)
            h = (h * (ll)239 + i) % mod;
        return h;
    }
};

unordered_map<string, pair<int, int>, myhash> q;

string arr[maxn];

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
    q.reserve(5e6);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        arr[i] = s;
        for (int j = 0; j < s.size(); j++)
            for (int k = 0; j + k < s.size(); k++){
                string t = s.substr(j, k + 1);
                if (q.find(t) == q.end())
                    q[t] = m_p(1, i);
                else
                if (q[t].sc != i)
                    q[t].fr++, q[t].sc = i;
            }
    }
    int zap;
    cin >> zap;
    while (zap--){
        string s;
        cin >> s;
        if (q.find(s) == q.end())
            cout << "0 -\n";
        else{
            auto w = q[s];
            cout << w.fr << ' ' << arr[w.sc] << '\n';
        }
    }
}