#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
int n , H[N] , W[N] , d[N + N] , D;

void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&W[i] , &H[i]);
        d[D ++] = W[i] , d[D ++] = H[i];
    }
    sort(d , d + D) , D = unique(d , d + D) - d;
    int m = n / 2;
    LL res = 1LL << 60;
    for (j = 0 ; j < D ; ++ j) {
        int h = d[j];
        int w = 0 , t = 0;
        vector<int> V;
        for (i = 0 ; i < n ; ++ i) {
            if (H[i] > h) {
                if (W[i] > h)
                    break;
                w += H[i];
                ++ t;
            } else {
                if (W[i] > h) {
                    w += W[i];
                } else {
                    w += W[i];
                    if (H[i] < W[i])
                        V.push_back(H[i] - W[i]);
                }
            }
        }
        if (i < n || t > m) continue;
        sort(V.begin() , V.end());
        for (i = 0 ; i < m - t && i < V.size() ; ++ i)
            w += V[i];
        res = min(res , (LL) w * h);
    }
    cout << res << endl;
}

int main () {
    work();
    return 0;
}