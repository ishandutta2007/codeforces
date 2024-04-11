#include <bits/stdc++.h>

using namespace std;

#define ep 1e-8

int n, w, m;
vector <double> v[111];

bool run() {
    if(m > 2 * n) return 0;
    int d = __gcd(m, n);
    if(m != 2 * n && m/d > n/d + 1) return 0;
    double x = 1. * w * n / m;
    double cur = w, ne = x;
    int id = 1, bin = 0;
    for(int i = 1; i <= m; i ++) {
        while(1) {
            if(cur > ne + ep) {
                cur -= ne;
                v[i].push_back(1. * id);
                v[i].push_back(ne);
                ne = x;
                break;
            } else {
                ne -= cur;
                v[i].push_back(1. * id);
                v[i].push_back(cur);
                id ++;
                bin = 0;
                cur = w;
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d%d%d", &n, &w, &m);
    if(run()) {
        puts("YES");
        for(int i = 1; i <= m; i ++) {
            for(int j = 0; j * 2 < (int)v[i].size(); j ++) {
                if(v[i][j * 2 + 1] > ep) printf("%.lf %.6lf ", v[i][j * 2], v[i][j * 2 + 1]);
            }
            puts("");
        }
    } else puts("NO");
    return 0;
}