#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Frac{
    ll x, y;
    Frac() {}
    Frac(ll _x, ll _y) : x(_x), y(_y) {
        ll g = __gcd(x, y);
        x /= g;
        y /= g;
        if (y < 0) {
            x = -x;
            y = -y;
        }
    }
    Frac operator+(const Frac& other) const{
        return Frac(x * other.y + y * other.x, y * other.y);
    }
    bool operator<(const Frac& other) const {
        return x * other.y < y * other.x;
    }
};

const int N = 2e5 + 10;
const int K = 20;
int n;
int cnt[N], sum[N];
vector<int> have[N];
int order[N];
int topOrder = 0;
int optT = 0;
Frac expected = Frac(0, 1);
vector<int> answer;

void build(int t) {
    for (int i = 0; i < topOrder; ++i) {
        int pos = order[i];
        sum[pos] = 0;
        for (auto val : have[pos]) {
            sum[pos] += min(val, t);
        }
    }
    sort(order, order + topOrder, [&] (int i, int j) {
        return sum[i] > sum[j];
    });
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m, k;
        cin >> m >> k;
        if (cnt[m] == 0) {
            order[topOrder++] = m;
        }
        cnt[m]++;
        sum[m] += k;
        have[m].push_back(k);
    }
    

    // small t
    {
        for (int t = 1; t <= min(topOrder, K); ++t) {
            build(t);
            vector<int> curAns;
            int curSum = 0;
            multiset<int> k;
            for (int curT = 1; curT <= t; ++curT) {
                curAns.push_back(order[curT - 1]);
                for (auto i : have[order[curT - 1]]) {
                    k.insert(i);
                }
                while (!k.empty() && *k.begin() < curT) {
                    curSum += *k.begin();
                    k.erase(k.begin());
                }
            }
            Frac cur = Frac(curSum, t) + Frac(k.size(), 1);
            if (expected < cur) {
                optT = t;
                expected = cur;
                answer = curAns;
            }
        }
    }

    // big t
    {
        int curSum = 0;
        multiset<int> k;
        vector<int> curAns;
        for (int t = 1; t <= topOrder; ++t) {
            curAns.push_back(t);
            for (auto i : have[order[t - 1]]) {
                k.insert(i);
            }
            while (!k.empty() && *k.begin() < t) {
                curSum += *k.begin();
                k.erase(k.begin());
            }
            // cerr << "curSum = " << curSum << endl;
            Frac cur = Frac(curSum, t) + Frac(k.size(), 1);
            if (expected < cur) {
                optT = t;
                expected = cur;
                answer = curAns;
            }
        }
    }

    sort(all(answer));
    cout << answer.size() << '\n';
    for (auto i : answer) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}