#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXD = 1100;
const int SVAL = 550;
const int MAXK = 25000000;

int N;
pair <int, int> q[MAXK];
int nq;
int grid[MAXD][MAXD];

int xc[4] = {-1, 1, 0, 0};
int yc[4] = {0, 0, -1, 1};

int main()
{
    for (int i = 0; i < MAXD; i++)
        for (int j = 0; j < MAXD; j++)
            grid[i][j] = 0;
    cin >> N;
    grid[SVAL][SVAL] = N;
    
    nq = 0;
    if (N >= 4)
    {
        q[0] = make_pair (SVAL, SVAL);
        nq = 1;
    }
    
    
    for (int i = 0; i != nq; (i = (i + 1) % MAXK))
    {
        int cx = q[i].first, cy = q[i].second;
        
        if (grid[cx][cy] >= 4)
        {
            int nt = grid[cx][cy] / 4;
            
            for (int j = 0; j < 4; j++)
            {
                int nx = cx + xc[j], ny = cy + yc[j];
                
                grid[nx][ny] += nt;
                if (grid[nx][ny] >= 4)
                {
                    q[nq] = make_pair (nx, ny);
                    nq++;
                    nq %= MAXK;
                }
                    //q.push_back (make_pair (nx, ny));
            }
            
            grid[cx][cy] -= 4 * nt;
        }
    }
    
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int x, y;
        cin >> x >> y;
        
        if (max (abs (x), abs (y)) > 500)
            cout << "0\n";
        else
            cout << grid[x+SVAL][y+SVAL] << "\n";
    }
    //system ("Pause");
    return 0;
}