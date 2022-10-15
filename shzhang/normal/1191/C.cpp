#include <iostream>

using namespace std;

long long p[100005];

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    int curitem = 1;
    //int curpage = (p[1] - 1) / k;
    long long curshift = 0;
    int curops = 0;
    while (curitem <= m) {
        long long thisitem = curitem;
        long long thisitem_page = (p[thisitem] - 1 - curshift) / k;
        long long delcnt = 0;
        while (curitem <= m && (p[curitem] - 1 - curshift) / k == thisitem_page) curitem++, delcnt++;
        curops++; curshift += delcnt;
    }
    printf("%d", curops);
    return 0;
}