#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 300*1000+5;

int n, q, unread;
int unreadin[maxn], lastchecked[maxn];
std::vector<int> m;

int main() {
    scanf("%d%d", &n, &q);
    std::fill(lastchecked, lastchecked+maxn, -1);
    int maxclear = 0;
    for (int i = 1; i <= q; i++) {
        int t, x; scanf("%d%d", &t, &x); 
        if (t == 1) {
            x--;
            m.pb(x);
            unreadin[x]++;
            unread++;
        } else if (t == 2) {
            x--;
            unread -= unreadin[x];
            unreadin[x] = 0;
            lastchecked[x] = sz(m);
        } else {
            assert(t == 3);
            while (maxclear < x) {
                if (lastchecked[m[maxclear]] <= maxclear) {
                    unreadin[m[maxclear]]--;
                    unread--;
                }
                maxclear++;
            }
        }
        printf("%d\n", unread);
    }
}