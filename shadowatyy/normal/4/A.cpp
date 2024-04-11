#include <bits/stdc++.h>
#define ll long long
using namespace std;

int w;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> w;

    if(w<4)
    {
        cout << "NO";
        return 0;
    }

    for(int i = 2; i <= w; i += 2)
    {
        if(i%2==0 && (w-i)%2==0)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}