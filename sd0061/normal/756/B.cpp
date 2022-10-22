#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n , t[N];
int f[N];

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &t[i]);
    }
    f[0] = 0;
    for (int i = 1 , j = 1 , k = 1 ; i <= n ; ++ i) {
        f[i] = f[i - 1] + 20;
        while (j < i && t[i] - t[j] >= 90) {
            ++ j;
        }
        if (t[i] - t[j] < 90) {
            f[i] = min(f[i] , f[j - 1] + 50);
        }
        while (k < i && t[i] - t[k] >= 1440) {
            ++ k;
        }
        if (t[i] - t[k] < 1440) {
            f[i] = min(f[i] , f[k - 1] + 120);
        }
        //   cout << t[i] << ' ' << t[j] << ' ' << t[k] << endl;
        printf("%d\n" , f[i] - f[i - 1]);
    }

}