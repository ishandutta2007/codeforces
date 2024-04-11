#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

const int N = 200 * 1000 + 5;
int n;
int a[N];
int ans[N];

bool read() {
    cin >> n;
    forn (i, n)
        cin >> a[i];
    return false;
}

int l[N], r[N];

void solve() {

    stack<int> st;

    forn (i, n) {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            l[i] = -1;
        else
            l[i] = st.top();
        st.push(i);
    }

    st = stack<int>();

    for (int i = n - 1; i >= 0; --i) {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            r[i] = n;
        else
            r[i] = st.top();
        st.push(i);
    }

    forn (i, n) {
        ans[r[i] - l[i] - 1] = max(ans[r[i] - l[i] - 1], a[i]);
    }

    for (int i = n; i > 0; --i)
        ans[i] = max(ans[i], ans[i + 1]);

    forn (i, n)
        cout << ans[i + 1] << ' ';
    cout << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    read();
    solve();
    
    return 0;
}