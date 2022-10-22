#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n , p[N] , b[N];
bool f[N];
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &p[i]);
        -- p[i];
    }
    int sum = 0 , loop = 0;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &b[i]);
        sum += b[i];
    }
    for (int i = 0 ; i < n ; ++ i) {
        if (!f[i]) {
            int x = i;
            ++ loop;
            while (!f[x]) {
                f[x] = 1;
                x = p[x];
            }
        }
    }
    int res = 0;
    if (~sum & 1) {
        ++ res;
    }
    if (loop > 1) {
        res += loop;
    }
    cout << res << endl;
}