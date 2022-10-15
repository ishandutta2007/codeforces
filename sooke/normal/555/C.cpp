#include <cstdio>
#include <set>

struct Element { int l, r, x, y; } e, u, v;

bool operator <(const Element &u, const Element &v) { return u.l == v.l ? u.r < v.r : u.l < v.l; }

int n, m, x, y, ans;
std::set<Element> set;

int main() {
    scanf("%d %d", &n, &m);
    set.insert((Element) {0, 0, 1, 1});
    set.insert((Element) {1, n, 1, 1});
    for (char opt; m; m--) {
        scanf("%d %d %c", &x, &y, &opt);
        e = *--set.lower_bound((Element) {x, n + 1, 1, 1});
        if (e.l <= x && x <= e.r) {
            set.erase(e);
            if (opt == 'L') {
                ans = x - e.x + 1;
                set.insert((Element) {e.l, x - 1, e.x, y + 1});
                set.insert((Element) {x + 1, e.r, e.x, e.y});
            } else {
                ans = y - e.y + 1;
                set.insert((Element) {e.l, x - 1, e.x, e.y});
                set.insert((Element) {x + 1, e.r, x + 1, e.y});
            }
        } else { ans = 0; }
        printf("%d\n", ans);
    }
    return 0;
}