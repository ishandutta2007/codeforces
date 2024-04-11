#include <bits/stdc++.h>
using namespace std;

int p[57];

int t[57];

int n, c, l, r, czas;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> c;

    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    czas = 0;

    for(int i = 1; i <= n; i++)
    {
        czas += t[i];

        l += max(0, p[i]-czas*c);
    }

    czas = 0;

    for(int i = n; i >= 1; i--)
    {
        czas += t[i];

        r += max(0, p[i]-czas*c);
    }

    if(l>r)
    {
        cout << "Limak";
        return 0;
    }

    if(l<r)
    {
        cout << "Radewoosh";
        return 0;
    }

    if(l==r)
    {
        cout << "Tie";
        return 0;
    }
}