#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
int main()
{
    int n, x;
    scanf("%d", &n);
    rep(i, n)
    {
        scanf("%d", &x);
        while (x--) printf(i ? "PLR" : "PRL");
        if (i + 1 < n) printf("R");
    }
    puts("");
    return 0;
}