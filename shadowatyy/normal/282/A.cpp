#include <bits/stdc++.h>
#define ll long long
using namespace std;

string w;

int n, res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    while(n--)
    {
        cin >> w;

        if(w[0]=='-' || w[2]=='-')
        {
            res--;
        }
        else
        {
            res++;
        }
    }

    cout << res;
}