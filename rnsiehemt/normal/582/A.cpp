#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
#define pb push_back
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); } 
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); } 
typedef long long ll;

int N, b[500 * 500 + 5], a[505], M;
std::map<int, int> c;

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N*N; i++) scanf("%d", &b[i]);

    std::sort(b, b+N*N); std::reverse(b, b+N*N);
    int s = 0, e = 0;
    while (s < N*N) {
        while (e < N*N && b[e] == b[s]) e++;
        for (int k = s; k < e; k++) {
            if (c[b[k]] > 0) c[b[k]]--;
            else {
                a[M++] = b[k];
                for (int i = 0; i < M-1; i++) {
                    c[gcd(a[i], a[M-1])] += 2;
                }
            }
        }
        s = e;
    }
    assert(N == M);
    for (int i = 0; i < N; i++) printf("%d%c", a[i], " \n"[i == N-1]);
}