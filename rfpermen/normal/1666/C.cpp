#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> segment;

void connect(vector<segment>& res, const pii& a, const pii& b) {
    if (a.first == b.first && a.second == b.second) {
        return;
    }

    if (a.first == b.first || a.second == b.second) {
        res.emplace_back(a, b);
        return;
    }

    const pii mid(a.first, b.second);
    connect(res, a, mid);
    connect(res, mid, b);
}

int main() {
    vector<pii> dat;
    vector<int> dat_x, dat_y;

    for (int i = 0; i < 3; i++) {
        int x,y; scanf("%d %d", &x, &y);

        dat.emplace_back(x, y);
        dat_x.push_back(x);
        dat_y.push_back(y);
    }

    sort(dat_x.begin(), dat_x.end());
    sort(dat_y.begin(), dat_y.end());

    const pii center(dat_x[1], dat_y[1]);

    vector<segment> res;
    connect(res, dat[0], center);
    connect(res, dat[1], center);
    connect(res, dat[2], center);

    printf("%d\n", (int)res.size());
    for (segment x: res) {
        printf("%d %d %d %d\n", x.first.first, x.first.second, x.second.first, x.second.second);
    }
    return 0;
}