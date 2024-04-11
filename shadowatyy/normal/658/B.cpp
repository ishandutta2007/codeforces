#include <bits/stdc++.h>
using namespace std;

int t[150007];

bool on[150007];

bool comp(int a, int b)
{
    return a[t]>b[t];
}

vector<int> D;

int n, d, q, typ, zap;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> d >> q;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    for(int i = 1; i <= q; i++)
    {
        cin >> typ >> zap;

        if(typ==1)
        {
            D.push_back(zap);

            on[zap] = true;

            if(D.size()>d)
            {
                sort(D.begin(), D.end(), comp);

                D.pop_back();
            }

        }

        if(typ==2)
        {
            sort(D.begin(), D.end(), comp);

            if(D.empty())
            {
                cout << "NO" << '\n';
                continue;
            }

            if(t[D.back()]<=t[zap] && on[zap])
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}