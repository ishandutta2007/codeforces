#include <algorithm>
#include <cstdio>
using namespace std;
int cnt, cnt1, cnt2, n, x;
struct ahah
{
    int x, pos;
} a[200005], b[200005], c[200005];
int ab(int a){
	return a<0?-a:a;
}
bool cmp(ahah a, ahah b)
{
    return ab(a.x) < ab(b.x);
}
int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);

        if(x == 0)c[++cnt].pos = i;

        if(x < 0)a[++cnt1].x = x, a[cnt1].pos = i;

        if(x > 0)b[++cnt2].x = x, b[cnt2].pos = i;
    }

    sort(a + 1, a + 1 + cnt1, cmp);
    sort(b + 1, b + 1 + cnt2, cmp);
    int v = -1;

    if(cnt != 0)
    {
        v = c[1].pos;

        for(int i = 2; i <= cnt; i++)
        {
            printf("1 %d %d\n", v, c[i].pos);
            v = c[i].pos;
        }
    }

    if(cnt == n)return 0;

    if(cnt1 % 2 == 0)
    {
        if(v != -1)printf("2 %d\n", v), v = -1;

        if(cnt1 != 0)
        {
            if(v == -1)v = a[1].pos;
            else printf("1 %d %d\n", v, a[1].pos), v = a[1].pos;

            for(int i = 2; i <= cnt1; i++)
            {
                printf("1 %d %d\n", v, a[i].pos);
                v = a[i].pos;
            }
        }

        if(cnt2 != 0)
        {
            if(v == -1)v = b[1].pos;
            else printf("1 %d %d\n", v, b[1].pos), v = b[1].pos;

            for(int i = 2; i <= cnt2; i++)
            {
                printf("1 %d %d\n", v, b[i].pos);
                v = b[i].pos;
            }
        }
    }
    else
    {
        if(v == -1)v = a[1].pos;
        else printf("1 %d %d\n", v, a[1].pos), v = a[1].pos;

        if(cnt + 1 != n)printf("2 %d\n", v), v = -1;
        else return 0;

        if(cnt1 > 1)
        {
            v = a[2].pos;

            for(int i = 3; i <= cnt1; i++)
           {
                printf("1 %d %d\n", v, a[i].pos);
                v = a[i].pos;
            }
        }

        if(cnt2 > 0)
        {
            if(v == -1)v = b[1].pos;
            else printf("1 %d %d\n", v, b[1].pos), v = b[1].pos;

            for(int i = 2; i <= cnt2; i++)
            {
                printf("1 %d %d\n", v, b[i].pos);
                v = b[i].pos;
            }
        }
    }
    return 0;
}