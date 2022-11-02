#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <random>
#include <deque>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) x.begin(), x.end()
//#define break_(x) {x; return;}
const ll MOD = 1000000007;
const ll P = 239;
const ll inf = 1e18;
const ld eps = 1e-9;
const ll MOD2 = 998244353;
ld pi = asin(0.5) * (ld)6;


struct Node {
    int left = -1, right = -1;
    int cnt = 0;
};

vector<Node> nodes;


void add(string const& s, int pos, int cur) {
    if (pos == s.size()) {
        ++nodes[cur].cnt;
        return;
    }

    if (s[pos] == '0') {
        if (nodes[cur].left == -1) {
            nodes[cur].left = nodes.size();
            nodes.emplace_back();
        }
        add(s, pos + 1, nodes[cur].left);
    } else if (s[pos] == '1') {
        if (nodes[cur].right == -1) {
            nodes[cur].right = nodes.size();
            nodes.emplace_back();
        }
        add(s, pos + 1, nodes[cur].right);
    }
}

int get_r(string const& x, int pos, int cur, int pw) {
    if (pos == x.size()) {
        return 0;
    }

    if (x[pos] == '0') {
        if (nodes[cur].right != -1)
            return get_r(x, pos + 1, nodes[cur].right, pw - 1) + (1 << pw);
        return get_r(x, pos + 1, nodes[cur].left, pw - 1);
    }
    else if (x[pos] == '1') {
        if (nodes[cur].left != -1)
            return get_r(x, pos + 1, nodes[cur].left, pw - 1) + (1 << pw);
        return get_r(x, pos + 1, nodes[cur].right, pw - 1);
    }
}

int get_l(string const& x, int pos, int cur, int pw) {
    if (pos == x.size()) {
        return 0;
    }
    if (x[pos] == '0') {
        if (nodes[cur].left != -1)
            return get_l(x, pos + 1, nodes[cur].left, pw - 1);
        return get_l(x, pos + 1, nodes[cur].right, pw - 1) + (1 << pw);
    }
    else if (x[pos] == '1') {
        if (nodes[cur].right != -1)
            return get_l(x, pos + 1, nodes[cur].right, pw - 1);
        return get_l(x, pos + 1, nodes[cur].left, pw - 1) + (1 << pw);
    }
}

#include <cassert>

void solve(int test_case)
{
    nodes.clear();
    nodes.emplace_back();

    int l, r;
    cin >> l >> r;
    vector<int> arr(r - l + 1);

    for (int& e : arr) {
        cin >> e;
        string s = bitset<18>(e).to_string();
        add(s, 0, 0);
    }

    for (int i = 0; i < (r - l + 1); ++i) {
        int x = arr[i] ^ r;
        int val = get_r(bitset<18>(x).to_string(), 0, 0, 17);
        int val2 = get_l(bitset<18>(x).to_string(), 0, 0, 17);
        if (l <= val2 && val <= r) {

            cout << x << endl;
            return;
        }
    }
}

int main(void)
{
    //freopen("euler.in", "r", stdin);
    //freopen("abc.out", "w", stdout);
    cout << fixed << setprecision(20);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; srand(time(0)); cin >> t;
    for (int i = 0; i < t; ++i) solve(i);
    return 0;
}