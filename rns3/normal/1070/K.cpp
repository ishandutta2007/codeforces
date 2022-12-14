#include <bits/stdc++.h>
using namespace std;

#define N 100005

int a[N];
int n, k, sum;

int main() {
	scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % k) {
        puts("No");
    }
    else {
        int d = sum / k;
        int now = 0, ns = 0, prv = 0;
        vector <int> vec;
        bool flag = 0;
        while (now <= n) {
            if (ns < d) {
                ns += a[++ now];
            }
            else if (ns == d) {
				vec.push_back(now - prv);
                prv = now;
                ns = 0;
                if (now == n) break;
            }
            else {
                flag = 1;
                break;
            }
        }
        if (flag) puts("No");
        else {
            puts("Yes");
            for (auto x : vec) {
                printf("%d ", x);
            }
        }
    }
    return 0;
}