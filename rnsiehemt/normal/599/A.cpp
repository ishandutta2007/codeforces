#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool look(T &a, T b = true) { return (a == b ? true : (a = b, false)); }
typedef long long ll;

int a, b, c;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", std::min(std::min(a+b+c, a+a+b+b), c+c + std::min(a+a, b+b)));
}