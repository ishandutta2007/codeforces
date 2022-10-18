#include <cstdio>
#include <algorithm>
char inp[1010][1010];

using namespace std;

int main()
{
    int can;
    scanf("%d", &can);
    for (int cas = 0; cas < can; cas++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i=0; i < n; i++)
        {
            scanf("%s", inp[i]);
        }

        int a1 = -n-m, a2=n+m, b1=-n-m, b2=n+m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (inp[i][j] == 'B')
                {
                    int a = i+j;
                    int b = i-j;
                    a1 = max(a,a1);
                    a2 = min(a,a2);
                    b1 = max(b,b1);
                    b2 = min(b,b2);
                }

            }
        }

        int a = (a1+a2), b = (b1+b2);
        int s = (a+b+2)/4, t = (a-b+2)/4;

        //printf("%d %d %d %d %d %d\n", a1, a2,b1, b2, s, t);
        int ans = -1;
        int as, at;
        for (int ds = -1; ds <=1; ds++)
        {
            for (int dt = -1; dt <=1; dt++)
            {
                int s2 = s+ds, t2=t+dt;
                if (s2 < 0 || s2 >=n ||t2 < 0 || t2 >=m) continue;

                int ca = max(max(s2+t2 - a2, a1 - (s2+t2)), max(s2-t2-b2, b1 - (s2-t2)));
                //printf("try s=%d t=%d ca=%d ans=%d\n", s2,t2,ca,ans);
                if (ans == -1 || ca < ans)
                {
                    ans = ca;
                    as = s2;
                    at = t2;
                }

            }
        }

        printf("%d %d\n", as+1, at+1);
    }
    return 0;
}