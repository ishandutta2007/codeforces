#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

int N, M;
int xc[4], yc[4];
bool sw;

int main()
{
    cin >> N >> M;
    
    sw = false;
    if (N > M)
    {
        swap (N, M);
        sw = true;
    }
    
    if (N == 0)
    {
        for (int i = 0; i < 4; i++)
            xc[i] = 0;
        yc[0] = 1;
        yc[1] = M;
        yc[2] = 0;
        yc[3] = M - 1;
    }
    else
    {
    
        double d, d2;
        d = 2 * sqrt (N * N + M * M) + M;
        d2 = 2 * sqrt ((N-1) * (N-1) + M * M) + sqrt (N * N + M * M);
        
        if (d > d2)
        {
            xc[0] = xc[3] = 0;
            xc[1] = xc[2] = N;
            yc[0] = yc[2] = 0;
            yc[1] = yc[3] = M;
        }
        else
        {
            xc[0] = 1;
            xc[1] = N;
            xc[2] = 0;
            xc[3] = N - 1;
            
            yc[0] = yc[2] = 0;
            yc[1] = yc[3] = M;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (sw)
        {
            swap (xc[i], yc[i]);
        }
    }
    
    for (int i = 0; i < 4; i++)
        cout << xc[i] << " " << yc[i] << "\n";
    //system ("Pause");
    return 0;
}