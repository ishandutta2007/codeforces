#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

ll n, m, a1, a2;
char s[1234];
set <int> st;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    while (n--) {
        scanf("%s", s);
        for (int i = 0; i < m; i++) {
            if (s[i] == 'G') a1 = i;
            if (s[i] == 'S') a2 = i;
        }
        if (a1 > a2) {
            cout << -1;
            return 0;
        }
        st.insert(a2 - a1);
    }
    cout << st.size();
    return 0;
}