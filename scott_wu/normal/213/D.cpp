#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 110;
const ld PI = acos ((ld)-1.0);

int N;
pair <ld, ld> res[5 * MAXN];
int ord[4] = {1, 3, 0, 2};

void solve (int cur)
{
    if (cur == N - 1)
    {
        for (int i = 0; i < 4; i++)
            cout << " " << ord[i] + 2 + 4 * cur;
        if (cur == 0)
            cout << " 1";
        else
            cout << " " << 4 * cur - 1;
    }
    else
    {
        cout << " " << 4 * cur + 3;
        solve (cur + 1);
        for (int i = 1; i < 4; i++)
            cout << " " << ord[i] + 2 + 4 * cur;
        if (cur == 0)
            cout << " 1";
        else
            cout << " " << 4 * cur - 1;
    }
}

int main()
{
    cin >> N;
    res[0] = make_pair (3.830127018922193, 3.366025403784439);
    res[1] = make_pair (-3.601321235851749, 10.057331467373021);
    res[2] = make_pair (0.466045194906253, 19.192786043799030);
    res[3] = make_pair (10.411264148588986, 18.147501411122495);
    res[4] = make_pair (12.490381056766580, 8.366025403784439);
    
    ld ang[4], dist[4];
    for (int i = 0; i < 4; i++)
    {
        ld xc = res[i+1].first - res[0].first, yc = res[i+1].second - res[0].second;
        dist[i] = sqrt (xc * xc + yc * yc);
        ang[i] = acos (xc / dist[i]);
    }
    
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res[4*i+j+1] = make_pair (res[4*(i-1)+j+1].first + res[2].first - res[0].first,
                                    res[4*(i-1)+j+1].second + res[2].second - res[0].second);
        }
    }
    
    cout << 4 * N + 1 << "\n";
    cout << fixed << setprecision (15);
    for (int i = 0; i < 4 * N + 1; i++)
        cout << res[i].first << " " << res[i].second << "\n";
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            cout << 1;
        else
            cout << 4 * i - 1;
        for (int j = 0; j < 4; j++)
            cout << " " << 4 * i + j + 2;
        cout << "\n";
    }
    cout << "1";
    solve (0);
    
    cout << "\n";
    //system ("Pause");
    return 0;
}