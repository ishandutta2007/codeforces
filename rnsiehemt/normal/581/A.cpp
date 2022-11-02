#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

int a, b;

int main()
{
    scanf("%d%d", &a, &b);
    int c = std::min(a, b), d = std::max(a, b) - c;
    printf("%d %d\n", c, d/2);
}