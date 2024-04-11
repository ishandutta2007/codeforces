#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int d[10][10];
int px[10][10], py[10][10];
int x1, y1, x2, y2;
char c1, c2;
 
queue < pair < int, int > > q;

int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1}; 

bool good(int x, int y)
{
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8) return true;
    return false;
}

vector <string> res;

int main()
{
    scanf("%c%d\n", &c1, &y1); x1 = c1 - 'a' + 1;
    scanf("%c%d", &c2, &y2); x2 = c2 - 'a' + 1;

    for (int i = 0; i < 10; i ++)
        for (int j = 0; j < 10; j ++)
            d[i][j] = -1;

    d[x1][y1] = 0;
    q.push(make_pair(x1, y1));
    while (!q.empty())
    {
        pair < int, int > p = q.front();
        int x = p.first, y = p.second; q.pop();

        for (int i = 0; i < 8; i ++)
            if (good(x + dx[i], y + dy[i]) && d[x + dx[i]][y + dy[i]] == -1)
            {
                d[x + dx[i]][y + dy[i]] = d[x][y] + 1;
                px[x + dx[i]][y + dy[i]] = x;
                py[x + dx[i]][y + dy[i]] = y;
                q.push(make_pair(x + dx[i], y + dy[i]));
            }
    }

    printf("%d\n", d[x2][y2]);
    int p = x2, q = y2;

    while (!(p == x1 && q == y1))
    {
        string cur = "";
        if (px[p][q] == p - 1) cur += 'R'; else
        if (px[p][q] == p + 1) cur += 'L';

        if (py[p][q] == q - 1) cur += 'U'; else
        if (py[p][q] == q + 1) cur += 'D';

        int np = px[p][q], nq = py[p][q];
        p = np, q = nq;
        res.push_back(cur);
    }

    for (int i = (int)(res.size()) - 1; i >= 0; i --)
        cout << res[i] << endl;

    return 0;
}