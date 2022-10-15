#include <cstdio>
#include <algorithm>

using namespace std;
#define ll long long

int n, d, x;

int getNextX() {
    x = ((ll)x * 37LL + 10007LL) % 1000000007;
    return x;
}

int a[100005];
int ainv[100005];
int b[100005];
int c[100005];

void initAB() {
    int i;
    for (i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for (i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for (i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main()
{
    scanf("%d%d%d", &n, &d, &x);
    initAB();
    if (d > 400) {
        for (int i = 0; i < n; i++) ainv[a[i]] = i;
        for (int i = 0; i < n; i++) {
            for (int j = n; j >= 1; j--) {
                if (i - ainv[j] >= 0 && b[i - ainv[j]]) {
                    c[i] = j; break;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!b[i]) continue;
            for (int j = 0; j < n; j++) {
                if (i + j < n) {
                    c[i+j] = max(c[i+j], a[j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) printf("%d\n", c[i]);
    return 0;
}