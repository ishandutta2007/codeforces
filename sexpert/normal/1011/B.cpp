
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a;
    cin >> n >> m;
    int count[110];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < m; i++)
    {
        cin >> a;
        count[a]++;
    }
    int y;
    //for(int i = 0; i < 100; i++) if(count[i] > 0) cout << i << " " << count[i] << endl;
    for(int i = 100; i > 0; i--)
    {
        y = i;
        int x = 0;
        for(int j = 1; j <= 100; j++)
        {
            x += count[j]/i;
        }
        if(x >= n) break;
        if(i == 1) y = 0;
    }
    cout << y << endl;
}