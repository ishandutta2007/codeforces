#include <bits/stdc++.h>
using namespace std;

int n, ax, ay, res;

string s;

int t[10];

int x[] = {2, 1, 2, 3, 1, 2, 3, 1, 2, 3};
int y[] = {1, 4, 4, 4, 3, 3, 3, 2, 2, 2};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> s;

    s = '#' + s;

    for(int i = 1; i <= n; ++i)
    {
        t[i] = s[i]-48;
    }

    for(int i = 0; i <= 9; ++i)
    {
        ax = x[i];
        ay = y[i];

        for(int j = 2; j <= n; ++j)
        {
            ax += (x[t[j]]-x[t[j-1]]);
            ay += (y[t[j]]-y[t[j-1]]);

            if(!((ax==2 && ay==1) || (ax>=1 && ax<=3 && ay>=2 && ay<=4)))
            {
                break;
            }

            if(j==n)
            {
                res++;
            }
        }
    }

    if(res==1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

}