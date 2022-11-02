#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 105;

int n, a[maxn];
std::string s;
std::vector<std::string> out;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    for (int i = 0; i < n; i++) s += '0';
    while (true) {
        int max = -1;
        std::vector<int> v;
        for (int i = 0; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
                v.clear();
                v.pb(i);
            } else if (a[i] == max) {
                v.pb(i);
            }
        }
        if (sz(v) == n) {
            break;
        } else if (sz(v) == 1) {
            int x = v[0];
            int other = 0;
            if (x == 0) other = 1;
            for (int i = 0; i < n; i++) if (i != x && a[i] > a[other]) other = i;
            a[x]--;
            if (a[other]) a[other]--;
            s[x] = s[other] = '1';
            out.eb(s);
            s[x] = s[other] = '0';
        } else if (sz(v)%2) {
            assert(max);
            int x = v[0], y = v[1], z = v[2];
            a[x] = a[y] = a[z] = max-1;
            s[x] = s[y] = s[z] = '1';
            out.eb(s);
            s[x] = s[y] = s[z] = '0';
        } else {
            assert(max);
            int x = v[0], y = v[1];
            a[x] = a[y] = max-1;
            s[x] = s[y] = '1';
            out.eb(s);
            s[x] = s[y] = '0';
        }
    }
    printf("%d\n", a[0]);
    printf("%d\n", sz(out));
    for (auto &x : out) printf("%s\n", x.c_str());
}