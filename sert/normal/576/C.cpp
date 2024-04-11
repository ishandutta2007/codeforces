#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e7 + 7;
const int M = 1e6 + 7;

struct dot {
    int x, y, n;
};

bool cmp1(const dot &a, const dot &b) {
    return a.x < b.x;
}

bool cmp2(const dot &a, const dot &b) {
    return a.x > b.x;
}

int dist(const dot &a, const dot &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int n, x, y;
vector <dot> a[1000][1000];
dot d, pr;
long long path = 0;

void print(dot x) {
    printf("%d ", x.n);
    if (pr.x != -1)
        path += dist(pr, x);
    pr = x;
}

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        /*x = (rand() * 1ll * rand() + rand()) % 1000001;
        y = (rand() * 1ll * rand() + rand()) % 1000001;
        if (x < 0 || x > 1000000) return 1;
        if (y < 0 || y > 1000000) return 1;*/
        d.x = x;
        d.y = y;
        d.n = i + 1;
        //cerr << x << " " << y << "\n";
        a[x / 1001][y / 1001].push_back(d);
        //cerr << i << "\n";
    }

    pr.x = -1;

    for (int i = 0; i < 1000; i++)
        if (i % 2 == 0)
            for (int j = 0; j < 1000; j++) {
                sort(a[j][i].begin(), a[j][i].end(), cmp1);
                for (int k = 0; k < a[j][i].size(); k++)
                    print(a[j][i][k]);
            }
        else
            for (int j = 999; j >= 0; j--) {
                sort(a[j][i].begin(), a[j][i].end(), cmp2);
                for (int k = 0; k < a[j][i].size(); k++)
                    print(a[j][i][k]);
            }

    //cerr << "\n" << path;
    //cerr << "\n" << "2500000000";

    return 0;
}