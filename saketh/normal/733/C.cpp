#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void fail() {
    cout << "NO\n";
    exit(0);
}

bool put(vector<pair<int, char>> &ans, vector<int> &vals, int beg, int end, int off) {
    for (int big = beg; big < end; big++) {
        vector<pair<int, char>> res;

        bool ok = true;
        int left = big - 1, right = big + 1;

        int size = vals[big];

        for (int it = 0; it < end - beg - 1; it++) {
            if (left >= beg && size > vals[left]) {
                res.emplace_back(left - beg + off + 1, 'L');
                size += vals[left];
                left--;
            } else if (right < end && size > vals[right]) {
                res.emplace_back(left - beg + off + 1, 'R');
                size += vals[right];
                right++;
            } else {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans.insert(ans.end(), all(res));
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    int K;
    cin >> K;

    vi fin(K);
    for (int i = 0; i < K; i++)
        cin >> fin[i];

    vector<pair<int, char>> ans;

    int inx = 0;
    int off = 0;

    for (int v : fin) {
        int sum = 0, end = inx;
        while (end < N && sum < v) {
            sum += vals[end];
            end++;
        }

        if (sum != v) {
            fail();
        }

        if (put(ans, vals, inx, end, off)) {
            inx = end;
            off++;
        }
        else fail();
    }

    if (inx != N)
        fail();

    cout << "YES\n";
    for (auto p : ans)
        cout << p.first + 1 << " " << p.second << "\n";
    return 0;
}