#include <bits/stdc++.h>
using namespace std;

int n, maks, indeks;

int t[107];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    for(int p = 1; p <= n; p++)
    {
        maks = -1;

        for(int i = p; i <= n; i++)
        {
            if(t[i]>maks)
            {
                maks = t[i];
                indeks = i;
            }
        }

        for(int l = indeks-1; l >= 1; l--)
        {
            swap(t[l], t[l+1]);
            cout << l << " " << l+1 << '\n';
        }
    }
}