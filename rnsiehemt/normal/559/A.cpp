#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
typedef long long ll;
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }

int t(int a) { return a*a; }
int a, b, c, d, e, f;

int main()
{
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d\n", t(b+a+f) - t(b) - t(f) - t(d));
}