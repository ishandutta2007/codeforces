#include <cstdio>
#include <set>
using namespace std;
multiset <int> s;
const int N = 1e6 + 34;
int a[N], n, x, len;
int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
void del(int x) {
    s.erase(s.find(x));
}
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &x);
        s.insert(x);
    }

    for (int i = 0; i < n; i++) {
        a[i] = *(s.rbegin());
        for (int j = 0; j <= i; j++)
            del(gcd(a[i], a[j]));
        for (int j = 0; j < i; j++)
            del(gcd(a[i], a[j]));
        printf("%d ", a[i]);
    }

    //for (multiset<int>::iterator it = s.begin(); it != s.end(); it++)
    //    printf("%d ", *it);
    return 0;
}