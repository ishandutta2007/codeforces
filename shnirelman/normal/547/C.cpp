#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int MX = 5e5 + 13;
const int LOG = 8;

/*
4 4
1 2 3 4
1
2
3
4

*/

int a[N];
vector<int> p[N], d[N];
int is[MX];
map<int, int> mp;
int s[1 << LOG];
li ans = 0;
bool used[N];
int cnt = 0;

int get(int i) {
    int res = 0;
    for(int mask = 1; mask < (1 << p[i].size()); mask++) {
        res += mp[d[i][mask - 1]] * (s[mask] % 2 == 0 ? 1 : -1);
    }
    return res + cnt;
}

void add(int i) {
    ans += get(i);
    for(auto x : d[i])
        mp[x]++;
    cnt++;
    used[i] = true;
}

void del(int i) {
    for(auto x : d[i])
        mp[x]--;
    cnt--;
    ans -= get(i);

    used[i] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 2; i < MX; i++) {
        if(is[i] == 0) {
            if(i * 1ll * i < MX)
                for(int j = i * i; j < MX; j += i)
                    is[j] = i;
        }
    }
//cout << "fr" << endl;
    for(int i = 0; i < n; i++) {
        int x = a[i];
//cout << i << endl;
        set<int> st;

        while(is[x] > 0) {
            st.insert(is[x]);
            x /= is[x];
        }

        if(x != 1)
            st.insert(x);

        for(auto y : st)
            p[i].push_back(y);
    }

    for(int i = 0; i < n; i++) {
        for(int mask = 1; mask < (1 << p[i].size()); mask++) {
            int x = 1;
            for(int j = 0; j < p[i].size(); j++)
                if(mask & (1 << j))
                    x *= p[i][j];
            d[i].push_back(x);
        }
    }

    for(int i = 0; i < (1 << LOG); i++) {
        for(int j = 0; j < LOG; j++)
            if(i & (1 << j))
                s[i]++;
    }

//    for(int i = 0; i < n; i++) {
//        cout << i << " : " << endl;
//        for(auto x : p[i])
//            cout << x << ' ';
//        cout << endl;
//        for(auto x : d[i])
//            cout << x << ' ';
//        cout << endl;
//    }

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;

//        for(auto p : mp)
//            cout << p.f << ' ' << p.s << endl;
//        cout << endl;

        if(used[x])
            del(x);
        else
            add(x);
        cout << ans << endl;
    }
}