#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

struct node {
    unordered_map<char, node*> next;
    int leaves;
    node() : next(), leaves(0) {}
};

node* root = new node();


bool isLetter(char c) {
    return 'a' <= c && c <= 'z';
}

int ans = 0;

void add(string s) {
    node* cur = root;
    int i = 0;
    int firstUnique = s.length();
    while (i < s.length()) {
        char c = s[i];
        if (cur->next.count(c) == 0) {
            break;
        }

        cur = cur->next[c];
        ++i;
        if (cur->leaves == 1) {
            firstUnique = min(i, firstUnique);
        }
    }

    bool isLeaf = cur->next.size() == 0;
    if (isLeaf) {
        ans += min(firstUnique + 1 + int(s.length()) - i, int(s.length()));
    } else {
        ans += s.length();
    }

    if (isLeaf && i == s.length()) {
        return;
    }

    cur = root;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (cur->next.count(c) == 0) {
            cur->next[c] = new node();
        }
        cur->leaves++;
        cur = cur->next[c];
    }
    cur->leaves++;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    char c;
    string word;
    cin >> noskipws;
    while (cin >> c) {
        if (isLetter(c)) {
            word += c;
        } else {
            ans++;
            if (word.length() > 0) {
                add(word);
                word = "";
            }
        }
    }

    if (word.length() > 0) {
        add(word);
    }

    cout << ans << '\n';
    
    return 0;
}