#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    int fug[15];
    memset(fug, 0, sizeof(fug));
    for(int i = 0; i <= 12; i++)
    {
        for(int a = 0; a <= 8; a++)
        {
            for(int b = 0; b <= 8; b++)
            {
                if(a + b <= i && (a == 0 || b <= 4))
                {
                    //cout << i << " " << a << " " << b << endl;
                    fug[i]++;
                }
            }
        }
    }
    /*set<int> sums;
    for(int a = 0; a <= 8; a++)
    {
        for(int b = 0; b <= 48; b++)
        {
            if(a + b <= 10 && (a == 0 || b <= 4))
            {
                //cout << i << " " << a << " " << b << endl;
                if(sums.count(4*a + 9*b + 49*(10 - a - b))) cout << "fugd up, ";
                cout << a << " " << b << " " << 10 - a - b << " " << 4*a + 9*b + 49*(10 - a - b) << endl;
                sums.insert(4*a + 9*b + 49*(10 - a - b));
            }
        }
    }*/
    for(int i = 0; i <= min(n, 12); i++)
    {
        if(i <= 12) ans += fug[i];
    }
    if(n > 12) ans += 49ll*(n - 12ll);
    cout << ans;
}