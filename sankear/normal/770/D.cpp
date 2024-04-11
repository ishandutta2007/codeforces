#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <cstring>
#include <cassert>

using namespace std;

#define pb push_back
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next hunext

using ll = long long;
using vi = vector<int>;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = 5050;

struct node {
    int level = 0;
    vector<node*> ch;
};

int y = 0;
char s[N];
int next[N];
char ans[N][N];

node* parse(int l, int r) {
    node* res = new node();
    if (l > r) {
        return res;
    }
    int nl = next[l];
    while (l <= r) {
        assert(s[l] == '[');
        assert(s[r] == ']');
        assert(nl <= r);
        assert(s[nl] == ']');
        res->ch.push_back(parse(l + 1, nl - 1));
        l = nl + 1;
        nl = next[l];
    }
    return res;
}

void dfs(node* v) {
    for (node* u : v->ch) {
        dfs(u);
        v->level = max(v->level, u->level + 1);
    }
}

inline void paint_vertical(int x, int level) {
    ans[x][y] = '+';
    for (int i = 1; i <= 1 + 2 * level; ++i) {
        ans[x + i][y] = '|';
    }
    ans[x + 1 + 2 * level + 1][y] = '+';
}

void paint(node* v, int x, int level) {
    if (sz(v->ch) == 0) {
        y += 2;
        return;
    }
    bool first = true;
    for (node* u : v->ch) {
        if (first) {
            first = false;
        } else {
            ++y;
        }
        
        paint_vertical(x, level);
        
        ++y;
        
        ans[x][y] = '-';
        ans[x + 1 + 2 * level + 1][y] = '-';
        
        paint(u, x + 1, level - 1);
        
        ans[x][y] = '-';
        ans[x + 1 + 2 * level + 1][y] = '-';
        
        ++y;
        
        paint_vertical(x, level);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    scanf("%s", s);
    vi st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            st.push_back(i);
        } else {
            assert(sz(st) > 0);
            next[st.back()] = i;
            st.pbk();
        }
    }
    assert(sz(st) == 0);
    node* root = parse(0, n - 1);
    dfs(root);
    paint(root, 0, root->level - 1);
    int height = 3 + (root->level - 1) * 2;
    int width = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = N - 1; j > width; --j) {
            if (ans[i][j]) {
                width = j;
                break;
            }
        }
    }
    ++width;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (ans[i][j] == 0) {
                ans[i][j] = ' ';
            }
        }
        puts(ans[i]);
    }
    return 0;
}