#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int N = 500000+10;
int Q, op[N], x[N];
vector<int> v;
double sum[N];
double cac(int x) {
    double ans = ( (double)v[(int)v.size()-1] + sum[x] ) / (double)(x+1);
    return ans;
}
int main() {
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i ++) {
        scanf("%d", &op[i]);
        if (op[i] == 1) {
            scanf("%d", &x[i]);
            v.push_back(x[i]);
            sum[v.size()] = sum[(int)v.size()-1] + x[i];
        } else {
            int L = 0, R = (int)v.size() - 1;
            while (R - L > 8) {
                int midL = (L + R) / 2;
                int midR = (midL + R) / 2;
                if (cac(midL) < cac(midR)) {
                    R = midR;
                } else {
                    L = midL;
                }
            }
            //printf("L = %d\n", L);
            double ans = 1e12;
            for (int d = -10; d <= 10; d ++) {
                int c = L + d;
                if (c < 0 || c > (int)v.size()-1) continue;
                ans = min(ans, cac(c));
            }

            printf("%.8f\n", (double)v[(int)v.size()-1] - ans);
        }

    }
}
/*
3
1 3
1 4
2
*/