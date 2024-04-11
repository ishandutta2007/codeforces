#include <cstdio>
#include <map>
#include <vector>
#include <utility>

using namespace std;

#define ll long long
#define encode(x, y) (200000LL * (ll)(x) + (ll)(y))

map<ll, int> sym_line;
map<ll, int> on_line;
map<ll, vector<pair<int, int> > > pts;

int Gcd(int a, int b)
{
    if (b == 0) return a;
    return Gcd(b, a % b);
}

int main()
{
    int q;
    scanf("%d", &q);
    int ptcnt = 0;
    for (int qry = 1; qry <= q; qry++) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            ptcnt++;
            ll dis = (ll)(x) * (ll)(x) + (ll)(y) * (ll)(y);
            pts[dis].push_back(make_pair(x, y));
            for (int i = 0; i < pts[dis].size(); i++) {
                int nx = pts[dis][i].first + x;
                int ny = pts[dis][i].second + y;
                int g = Gcd(nx, ny);
                nx /= g; ny /= g;
                sym_line[encode(nx, ny)]++;
            }
            int G = Gcd(x, y);
            on_line[encode(x / G, y / G)]++;
        } else if (t == 2) {
            ptcnt--;
            int G = Gcd(x, y);
            on_line[encode(x / G, y / G)]--;
            ll dis = (ll)(x) * (ll)(x) + (ll)(y) * (ll)(y);
            for (int i = 0; i < pts[dis].size(); i++) {
                int nx = pts[dis][i].first + x;
                int ny = pts[dis][i].second + y;
                int g = Gcd(nx, ny);
                nx /= g; ny /= g;
                sym_line[encode(nx, ny)]--;
            }
            for (int i = 0; i < pts[dis].size(); i++) {
                if (pts[dis][i].first == x && pts[dis][i].second == y) {
                    pts[dis][i].first = pts[dis].back().first;
                    pts[dis][i].second = pts[dis].back().second;
                    pts[dis].pop_back(); break;
                }
            }
        } else {
            int g = Gcd(x, y);
            x /= g; y /= g;
            //printf("%d %d\n", sym_line[encode(x, y)], on_line[encode(x, y)]);
            printf("%d\n", ptcnt - 2 * sym_line[encode(x, y)] + on_line[encode(x, y)]);
        }
    }
}