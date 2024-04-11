#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
struct P {
    int a, d, i;
} p[N];

int s[N];

int get_rank(int x) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(i == x) continue;
        cnt += (s[i] > s[x] || (s[i] == s[x] && i < x));
    }
    return cnt;
}

int sign(int x) {
    return x == 0 ? 0 : x / abs(x);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].a >> p[i].d;
        s[i] = p[i].a;
        p[i].i = i;
    }
    sort(p, p + n, [](const P &p1, const P &p2) {
        if(sign(p1.d) != sign(p2.d)) return sign(p1.d) < sign(p2.d);
        if(p1.d < 0) return p1.a == p2.a ? p1.i < p2.i : p1.a > p2.a;
        else return p1.a == p2.a ? p1.i > p2.i : p1.a < p2.a;
    });
    int res = 0;
    for(int i = 0; i < n; i++) {
        int dif = get_rank(p[i].i);
        s[p[i].i] += p[i].d;
        dif = abs(dif - get_rank(p[i].i));
        res += dif;
    }
    cout << res << endl;

}