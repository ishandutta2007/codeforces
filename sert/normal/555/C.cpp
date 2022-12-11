#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

const int inf = 1e9 + 34;
set <int> xu, xd;
set <int> :: iterator it;
int n, m, xx, yy, p;
//map <int, int> mv;
set <pair<int, char> > md;
map <pair<int, char>, int> mv;
char ch, c;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d %d ", &n, &m);

    ///for (int i = 0; i < m; i++) tx[i] = ty[i] = inf;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %c ", &xx, &yy, &ch);

        if (md.find(make_pair(xx, 'L')) != md.end()) {
            cout << "0\n";
            continue;
        }

        if (md.find(make_pair(xx, 'U')) != md.end()) {
            cout << "0\n";
            continue;
        }
        //cerr << xx << " " << yy << " " << ch << " <- ";
        if (ch == 'U') {
            it = xu.lower_bound(xx);
            if (it == xu.end()) {
                mv[make_pair(xx, ch)] = 0;
            } else {
                p = *it;
                if (md.find(make_pair(p, 'L')) != md.end())
                    mv[make_pair(xx, ch)] = n + 1 - p;
                else
                    mv[make_pair(xx, ch)] = mv[make_pair(p, 'U')];
            }
            cout << yy - mv[make_pair(xx, ch)] << "\n";
        } else {
            it = xd.lower_bound(-xx);
            if (it == xd.end()) {
                mv[make_pair(xx, ch)] = 0;
            } else {
                p = -(*it);
                if (md.find(make_pair(p, 'U')) != md.end())
                    mv[make_pair(xx, ch)] = p;
                else
                    mv[make_pair(xx, ch)] = mv[make_pair(p, 'L')];
            }
            cout << xx - mv[make_pair(xx, ch)] << "\n";
        }

        xu.insert(xx);
        xd.insert(-xx);
        md.insert(make_pair(xx, ch));
    }



    return 0;
}