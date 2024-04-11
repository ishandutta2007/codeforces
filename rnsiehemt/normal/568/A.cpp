#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
typedef long long ll;
template <typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template <typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }

const int Max = 1*1000*1000 + 200*1000;

ll P, Q, pi[Max], rub[Max];
bool prime[Max], palin[Max];

int d[10], L;
void g(int L) {
    int k = 0;
    for (int i = 0; i < L; i++) k = (k*10 + d[i]);
    if (k < Max) palin[k] = true;
}
void f(int i) {
    L = 0;
    for (; i; i /= 10) d[L++] = i%10;
    std::reverse(d, d+L);
    for (int i = 0; i < L; i++) d[L+L-1 - i] = d[i];
    g(L+L);
    for (int i = 0; i < L-1; i++) d[L+L-2 - i] = d[i];
    g(L+L-1);
}

int main()
{
    std::fill(prime+2, prime+Max, true);
    for (int i = 2; i < Max; i++) {
        if (prime[i]) for (int j = i+i; j < Max; j += i) prime[j] = false;
        pi[i] = pi[i-1] + prime[i];
    }
    //for (int i = 1; i < 10; i++) printf("%d %d\n", i, prime[i]);
    
    //int magic = 0;
    for (int i = 0; i < 10000; i++) {
        f(i);
        /*if (palin[i]) {
            if (magic++ < 30) {
                printf("%d %d\n", i, palin[i]);
            }
        }*/
    }
    for (int i = 1; i < Max; i++) rub[i] = rub[i-1] + palin[i];
    
    scanf("%lld%lld", &P, &Q);
    for (int i = Max-1; i >= 0; i--) if (pi[i] * Q <= P * rub[i]) {
        //printf("%lld %lld\n", pi[i], rub[i]);
        printf("%d\n", i);
        return 0;
    }

    printf("Palindromic tree is better than splay tree\n");
}