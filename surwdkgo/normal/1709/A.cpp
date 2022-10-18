#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cinttypes>

using namespace std;

#define MAXN 1000010
#define F first
#define S second

int main()
{
    int casN;
    scanf("%d", &casN);
    for (int cas = 0; cas < casN; cas++)
    {
        int vis[5];
        int key[5];
        int st;
        for (int i = 0; i < 3; i++) vis[i] = 0;
        scanf("%d",&st);
        for (int i = 0; i < 3; i++) scanf("%d", &key[i]);
        int cnt = 0;
        while (st != 0 && !vis[st-1])
        {
            vis[st-1]=1;
            st = key[st-1];
            cnt++;
        }
        printf(cnt == 3 ? "YES\n" : "NO\n");


    }

    return 0;
}