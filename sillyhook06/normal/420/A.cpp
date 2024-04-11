#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
    int x = 0;
    char ch = getchar();
    bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if
#define rep(i,n) for (int i=0;i<n;++i)

int n, flag;
bool check(char x)
{
    return x == 'A' || x == 'H' || x == 'I' || x == 'M' || x == 'O' || x == 'T' || x == 'U' || x == 'V' || x == 'W' || x == 'X' || x == 'Y';
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    string s, t;
    cin >> s, n = s.size(), t = s, reverse(t.begin(), t.end()), flag = s == t;
    rep(i, n) if (!check(s[i])) flag = 0;
    puts(flag ? "YES" : "NO");
    return 0;
}