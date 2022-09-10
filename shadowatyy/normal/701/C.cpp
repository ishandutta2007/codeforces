#include <bits/stdc++.h>
using namespace std;

int n, ile, aktualnie, k, res = 1000007;

string s;

map<char, int> M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> s;

    s = '#' + s;

    for(int i = 1; i <= n; ++i)
    {
        ++M[s[i]];

        if(M[s[i]]==1)
        {
            ++ile;
        }
    }

    M.clear();

    ++M[s[1]];

    aktualnie = 1;

    k = 1;

    for(int p = 1; p <= n; ++p)
    {
        while(aktualnie<ile && k<n)
        {
            ++k;

            ++M[s[k]];

            if(M[s[k]]==1)
            {
                ++aktualnie;
            }
        }

        if(aktualnie==ile)
        {
            res = min(res, k-p+1);
        }

        --M[s[p]];

        if(M[s[p]]==0)
        {
            --aktualnie;
        }
    }

    cout << res;

}