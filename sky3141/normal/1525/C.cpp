#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 300000 + 9;

struct Robot
{
    int id;
    int pos;
    char direction;
};

int T;
int n, m;
Robot robot[MAXN];
Robot *stack[MAXN];
int top;
int ans[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            cin >> robot[i].pos;
            robot[i].id = i;
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> robot[i].direction;
        }

        sort(robot, robot + n, [](const Robot &a, const Robot &b){ return a.pos < b.pos; });

        memset(ans, -1, sizeof(ans));

        for (int isodd = 0; isodd < 2; ++isodd)
        {
            top = 0;

            for (int i = 0; i < n; ++i)
            {
                if ((robot[i].pos & 1) == isodd) continue;
                Robot *cur = &robot[i];
                if (cur->direction == 'L')
                {
                    if (top > 0)
                    {
                        Robot *p = stack[top--];
                        ans[p->id] = ans[cur->id] = (cur->pos - p->pos) >> 1;
                    }
                    else
                    {
                        cur->pos = -cur->pos;
                        stack[++top] = cur;
                    }
                }
                else
                {
                    stack[++top] = cur;
                }
            }
            while (top >= 2)
            {
                Robot *p1 = stack[top--], *p2 = stack[top--];
                ans[p1->id] = ans[p2->id] = m - ((p1->pos + p2->pos) >> 1);
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}