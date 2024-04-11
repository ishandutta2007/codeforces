#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, K, a[MaxN], foo[] = {0,1,0,1,2,0,2,0};

int g(int i) {
    if (i < 8 || i%2 == 1) return 2;
    else return 3 - g(i/2);
}
int f(int i) {
    if (i < 8) return foo[i];
    else if (i%2) return 0;
    else return g(i);
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    if (K%2 == 0) {
        int k = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] == 1) k ^= 1;
            if (a[i] == 2) k ^= 2;
            if (a[i] >= 4 && a[i]%2 == 0) k ^= 1;
        }
        printf("%s\n", k ? "Kevin" : "Nicky");
    } else {
        int k = 0;
        for (int i = 0; i < N; i++) {
            k ^= f(a[i]);
        }
        printf("%s\n", k ? "Kevin" : "Nicky");
    }
}