//7
#include <bits/stdc++.h>
using namespace std;
#define N 50010
#define inf 1000000007
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back
#define all(x) x.begin(), x.end()

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, q, tot;
map <string, int> mp;
vector <int> vec[N<<4];
char s[N][10];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s[i]);
        int len = strlen(s[i]);
        for (int j = 0; j < len; j ++) {
            string str = string();
            for (int k = j; k < len; k ++) {
                str += s[i][k];
                int &id = mp[str];
                if (!id) id = ++ tot;
                vec[id].pb(i);
            }
        }
    }
    for (int i = 1; i <= tot; i ++) {
        sort(all(vec[i]));
        int m = unique(all(vec[i])) - vec[i].begin();
        while (vec[i].size() > m) vec[i].pop_back();
    }
    scanf("%d", &q);
    while (q --) {
        scanf("%s", s[0]);
        int id = mp[s[0]];
        if (!id) puts("0 -");
        else printf("%d %s\n", vec[id].size(), s[vec[id][0]]);
    }

    return 0;
}