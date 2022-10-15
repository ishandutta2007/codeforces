#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
char a[100005];
char b[100005];

void solve(char* s, vector<int>& ans)
{
    s[n + 1] = '0';
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i+1]) ans.push_back(i);
    }
}

void work(void)
{
    scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    vector<int> op1, op2;
    solve(a, op1);
    solve(b, op2);
    printf("%d ", (int)(op1.size() + op2.size()));
    for (int i = 0; i < op1.size(); i++) {
        printf("%d ", op1[i]);
    }
    reverse(op2.begin(), op2.end());
    for (int i = 0; i < op2.size(); i++) {
        printf("%d ", op2[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}