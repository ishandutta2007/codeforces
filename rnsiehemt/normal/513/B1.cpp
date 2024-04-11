#include <bits/stdc++.h>

struct S {
    int a[8];
    int s;
    bool operator<(const S &o) const {
        if (s == o.s) {
            for (int i = 0; true; i++) {
                if (a[i] < o.a[i]) return true;
                else if (a[i] > o.a[i]) return false;
            }
        }
        else return s > o.s;
    }
};

int N, M, K;
int a[55];
S s[42000];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) a[i] = i+1;

    do {
        for (int i = 0; i < N; i++)
            s[K].a[i] = a[i];
        for (int i = 0; i < N; i++) for (int j = i+1; j <= N; j++)
            s[K].s += *std::min_element(a+i, a+j);
        K++;
    } while (std::next_permutation(a, a+N));

    std::sort(s, s+K);
    for (int i = 0; i < N; i++) printf("%d%c", s[M-1].a[i], " \n"[i==N-1]);
}