#include <bits/stdc++.h>
using namespace std;

int n;

int t[5007];

int res[5007];

int a[5007];

void subs(int s)
{
    int m = 0;
    int index = 1000000;

    for(int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }

    for(int i = s; i <= n; i++)
    {
        a[t[i]]++;

        if(a[t[i]]>m)
        {
            m = a[t[i]];
            index = t[i];
        }
        else
        {
            if(a[t[i]]==m && t[i]<index)
            {
                index = t[i];
            }
        }

        res[index]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    for(int i = 1; i <= n; i++)
    {
        subs(i);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
}