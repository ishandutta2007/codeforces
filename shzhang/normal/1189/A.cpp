#include <cstdio>

using namespace std;

int n;
char str[105];
int ends[105]; int nextend = 1;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    ends[0] = -1;

    int cur = 0;
    while (cur < n) {
        int zerocnt = 0;
        int onecnt = 0;
        int best = cur;
        for (int curend = cur; curend < n; curend++) {
            if (str[curend] == '0')
                zerocnt++;
            else
                onecnt++;
            if (zerocnt != onecnt) best = curend;
        }
        ends[nextend] = best; nextend++;
        cur = best + 1;
    }
    printf("%d\n", nextend - 1);
    for (int i = 1; i <= nextend; i++) {
        for (int j = ends[i-1] + 1; j <= ends[i]; j++) printf("%c", str[j]);
        printf(" ");
    }
    return 0;
}