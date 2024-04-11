#include <cstdio>

using namespace std;

#define ll long long

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b, a%b);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int r, b, k;
        scanf("%d%d%d", &r, &b, &k);
        if (r > b) {
            int t = r; r = b; b = t;
        }
        int gc = GCD(r, b);
        r /= gc; b /= gc;
        printf((ll)r * (ll)(k-1) + 1 <= b - 1 ? "REBEL\n" : "OBEY\n");
    }
    return 0;
}