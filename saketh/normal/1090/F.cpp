#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi sec = { 58348942, 78896476, 58352905, 43967598, 16113678, 71225151 };
int test(int i, int j, int k) {
    return min({ sec[i], sec[j], sec[k] }) +
           max({ sec[i], sec[j], sec[k] });
}

int test(int inx, vi query) {
    vi args;
    for (int i = 0; i < 5; i++)
        if (query[i])
            args.push_back(inx + i);
    return test(args[0], args[1], args[2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    auto solve = [](int inx) {
        vvi ask;
        vi get;

        vi query = { 1, 1, 1, 0, 0 };
        do {
            ask.push_back(query);
            cout << "?";
            for (int i = 0; i < 5; i++) {
                if (query[i])
                    cout << " " << inx + i + 1;
            }
            cout << endl;

            int res;
            cin >> res;
            //res = test(inx, query);
            get.push_back(res);
        } while (next_permutation(all(query), greater<int>()));

        vi vals = get;
        sort(all(vals));

        ll ac = vals[0], ad = vals[1];
        ll be = vals[8], ce = vals[9];
        ll ae = vals[4];
        ll bd = (vals[3] != vals[4]) ? vals[3] : vals[6];

        ll sum = (ac + ad + be + ce + bd) / 2;

        int a = sum - bd - ce;
        int b = sum - ad - ce;
        int c = ac - a;
        int d = ad - a;
        int e = ae - a;

        array<int, 5> nums = { a, b, c, d, e };
        do {
            bool good = true;
            for (int q = 0; q < 10; q++) {
                int minv = INT_MAX, maxv = INT_MIN;
                for (int i = 0; i < 5; i++) {
                    if (ask[q][i]) {
                        minv = min(minv, nums[i]);
                        maxv = max(maxv, nums[i]);
                    }
                }
                good &= (minv + maxv) == get[q];
            }
            if (good) break;
        } while (next_permutation(all(nums)));

        return nums;
    };

    int N;
    cin >> N;

    vi vals(N);
    for (int i = 0; i + 5 <= N; i += 5) {
        array<int, 5> v = solve(i);
        for (int j = 0; j < 5; j++)
            vals[i + j] = v[j];
    }
    if (N % 5) {
        array<int, 5> v = solve(N - 5);
        for (int j = 0; j < 5; j++)
            vals[N - 5 + j] = v[j];
    }

    cout << "!";
    for (int i = 0; i < N; i++)
        cout << " " << vals[i];
    cout << endl;

    return 0;
}