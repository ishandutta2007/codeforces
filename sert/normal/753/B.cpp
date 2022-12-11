#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ != 4 && __GNUC_MINOR__ != 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e4;
const ll INF = 1e10;

vector<int> ko(int x) {
    return {x / 1000, x / 100 % 10, x / 10 % 10, x % 10};
}

pair <int, int> req(int my, int val) {
    bool u[10];
    for (int i = 0; i < 10; i++) u[i] = false;
    auto a = ko(my);
    auto b = ko(val);
    int byk = 0;
    for (int i = 0; i < 4; i++) byk += int(a[i] == b[i]);
    for (int i = 0; i < 4; i++) u[a[i]] = true;
    int kor = 0;
    for (int i = 0; i < 4; i++) kor += int(u[b[i]]);
    return {byk, kor - byk};
}

int main() {
    //init();
    int a, b, c, d;
    vector <int> v;
    for (int i = 0; i < N; i++) {
        a = i / 1000;
        b = i / 100 % 10;
        c = i / 10 % 10;
        d = i % 10;
        if (a != b && a != c && a != d && b != c && b != d && c != d) {
            v.push_back(i);
        }
    }

    pair <int, int> q;
    int p;
    int x;
    srand(3431);
    while (true) {
        x = v[rand() % v.size()];
        printf("%04d\n", x);
        fflush(stdout);
        scanf("%d%d", &q.first, &q.second);
        p = v.size() - 1;
        if (q.first == 4)
            return 0;
        if (p == 0)
            return 34;
        while (p >= 0) {
            if (q != req(v[p], x)) {
                swap(v[p], v.back());
                v.pop_back();
            }
            p--;
        }
    }

    return 0;
}