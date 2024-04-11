#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int d;
    cin >> d;
    
    if (d == 0)
    {
        if (n == 1)
            puts("0");
        else
            puts("No solution");
        return;
    }

    cout << d;

    while(--n)
        cout << "0";
    cout << endl;

}

int main()
{
    solve();
    return 0;
}