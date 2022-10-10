#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> fact;
    for(int d = 2; d <= n; d++)
    {
        if(n == 1)
            break;
        while(n % d == 0)
        {
            n /= d;
            fact[d]++;
        }
    }
    int ans = 1, moves = 0;
    for(auto p : fact)
    {
        ans *= p.first;
        //cout << p.first << " " << p.second << endl;
        for(int i = 1; p.second > (1 << (i - 1)); i++)
        {
            moves = max(moves, i);
        }
    }
    for(auto p : fact)
    {
        if(p.second < (1 << moves))
        {
            moves++;
            break;
        }
    }
    cout << ans << " " << moves << endl;
}