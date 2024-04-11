#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, m;
char tmp[2005];
bool turns_on[2005][2005];
int turned_on_times[2005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", tmp + 1);
        for (int j = 1; j <= m; j++) {
            turns_on[i][j] = (tmp[j] == '1');
            if (turns_on[i][j]) turned_on_times[j]++;
        }
    }
    bool ans = false;
    for (int i = 1; i <= n; i++) {
        bool none_needed = true;
        for (int j = 1; j <= m; j++) {
            if (turns_on[i][j] && turned_on_times[j] == 1) {
                none_needed = false;
            }
        }
        if (none_needed) {
            ans = true; break;
        }
    }
    printf("%s", ans ? "YES" : "NO");
    return 0;
}