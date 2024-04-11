#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

void sum(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

vector<vector<ll>> mul(const vector<vector<ll>>& l, const vector<vector<ll>>& r) {
    vector<vector<ll>> ans(3, vector<ll>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                sum(ans[i][j], mul(l[i][k], r[k][j]));
            }
        }
    }
    return ans;
}

vector<ll> mul(const vector<ll>& v, const vector<vector<ll>>& mat) {
    vector<ll> ans(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum(ans[i], mul(v[j], mat[j][i]));
        }
    }
    return ans;
}

vector<vector<ll>> todeg(vector<vector<ll>> mat, ll d) {
    if (d == 0) {
        return { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    }
    vector<vector<ll>> ans = todeg(mat, d / 2);
    ans = mul(ans, ans);
    if (d % 2 == 1) {
        ans = mul(ans, mat);
    }
    /*for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, int>> prep;
    for (int i = 0; i < n; ++i) {
        ll a, l, r;
        cin >> a >> l >> r;
        prep.push_back({ l, a });
        prep.push_back({ r + 1, 0 - a });
    }
    prep.push_back({ m + 1, 0 });
    sort(prep.begin(), prep.end());

    vector<ll> ans({ 0, 1, 0 });
    vector<int> open(4, 0);
    ll last = 1;
    for (int i = 0; i < prep.size(); ++i) {
        vector<vector<ll>> mat({ { 1, 1, 0 }, { 1, 1, 1 }, { 0, 1, 1 } });
        for (int i = 0; i < 3; ++i) {
            if (open[i + 1] > 0) {
                for (int j = 0; j < 3; ++j) {
                    mat[j][i] = 0;
                }
            }
        }
        ans = mul(ans, todeg(mat, prep[i].first - 1 - last));
        last = prep[i].first - 1;
        if (prep[i].second >= 0) {
            ++open[prep[i].second];
        }
        else {
            --open[0 - prep[i].second];
        }
        //cout << prep[i].first - 1 << ": " << ans[0] << " " <<  ans[1] << " " << ans[2] << "\n";
    }

    cout << /*ans[0] << " " <<*/ ans[1] /*<< " " << ans[2]*/ << "\n";

    return 0;
}