#include <iostream>
#include <stack>
using namespace std;

int l[1000005];
int r[1000005];
int dl[1000005];
int dr[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    stack<int> stl, str;
    stl.push(0);
    dl[0]++;
    for (int i = 1; i <= n; i++)
    {
        str.push(0);
        dr[0]++;
    }
    int x = 1;
    int ml = 0, mr = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            int e = str.top();
            str.pop();
            if (r[x] >= 0)
            {
                dr[r[x]]--;
            }
            else
            {
                c--;
            }
            if (!dr[mr])
            {
                mr--;
            }
            x++;
            stl.push(-e);
            l[x] = l[x - 1] - e;
            if (l[x] >= 0)
            {
                dl[l[x]]++;
            }
            else
            {
                c++;
            }
            ml = max(ml, l[x]);
        }
        else if (s[i] == 'L')
        {
            if (x > 1)
            {
                int e = stl.top();
                stl.pop();
                if (l[x] >= 0)
                {
                    dl[l[x]]--;
                }
                else
                {
                    c--;
                }
                if (!dl[ml])
                {
                    ml--;
                }
                x--;
                str.push(-e);
                r[x] = r[x + 1] - e;
                if (r[x] >= 0)
                {
                    dr[r[x]]++;
                }
                else
                {
                    c++;
                }
                mr = max(mr, r[x]);
            }
        }
        else
        {
            if (r[x] >= 0)
            {
                dr[r[x]]--;
            }
            else
            {
                c--;
            }
            int e = str.top();
            r[x] -= e;
            if (!dr[mr])
            {
                mr--;
            }
            str.pop();
            if (s[i] == '(')
            {
                r[x]--;
                str.push(-1);
            }
            else if (s[i] == ')')
            {
                r[x]++;
                str.push(1);
            }
            else
            {
                str.push(0);
            }
            if (r[x] >= 0)
            {
                dr[r[x]]++;
            }
            else
            {
                c++;
            }
            mr = max(mr, r[x]);
        }
        if (!c && r[x] == l[x])
        {
            cout << max(ml, mr) << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    cout << "\n";
}