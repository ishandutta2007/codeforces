#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, h, k, mult = 1;
    cin >> w >> h >> k;
    int ans = 0;
    for(int i = 0; i < 2*k; i++)
    {
        if(w < 0 || h < 0)
            break;
        ans += mult*w*h;
        w -= 2;
        h -= 2;
        mult *= -1;
    }
    cout << ans << endl;
}