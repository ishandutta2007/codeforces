#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>
#include <cassert>

using namespace std;
typedef long long ll;
const int MAXN = 22;

int N, M;
int orr[MAXN][MAXN];
int arr[MAXN][MAXN];

vector <vector <int> > moves;

vector <int> gmove (int x, int y)
{
    vector <int> res;
    res.push_back(x);
    res.push_back(y);
    res.push_back(x-1);
    res.push_back(y);
    res.push_back(x-1);
    res.push_back(y+1);
    res.push_back(x);
    res.push_back(y+1);

    res.push_back(x);
    res.push_back(y);
    res.push_back(x);
    res.push_back(y+1);
    res.push_back(x);
    res.push_back(y-1);
    res.push_back(x-1);
    res.push_back(y-1);
    
    res.push_back(x);
    res.push_back(y);
    res.push_back(x-1);
    res.push_back(y+1);
    res.push_back(x-1);
    res.push_back(y);
    res.push_back(x-1);
    res.push_back(y-1);
    res.push_back(x);
    res.push_back(y-1);
    res.push_back(x);
    res.push_back(y+1);
    return res;
}

void op (int x, int y, int x2, int y2)
{
    int ox = x, oy = y;
    // x2 == x+1 || y2 == y+1

    bool vflip = (x2 == x + 1);
    bool xflip = (x == 0);
    if (xflip)
    {
        if (vflip)
            x = N - 2 - x;
        else
            x = N - 1 - x;
    }
    bool yflip = (y == 0);
    if (yflip)
    {
        if (vflip)
            y = M - 1 - y;
        else
            y = M - 2 - y;
    }

    if (vflip)
    {
        swap (x, y);
    }

    vector <int> r = gmove (x, y);
    for (int i = 0; i < r.size(); i += 2)
    {
        if (vflip)
            swap (r[i], r[i+1]);
    }
    for (int i = 0; i < r.size(); i += 2)
    {
        if (xflip)
            r[i] = N - 1 - r[i];
    }
    for (int i = 1; i < r.size(); i += 2)
    {
        if (yflip)
            r[i] = M - 1 - r[i];
    }

    //for (int i = 0; i < r.size(); i++)
    //    cout << r[i] << "\n";
    
    vector <int> v;
    for (int i = 0; i < 4; i++)
    {
        v.push_back(arr[r[2*i]][r[2*i+1]]);
    }
    moves.push_back(v);

    v.clear();
    for (int i = 4; i < 8; i++)
    {
        v.push_back(arr[r[2*i]][r[2*i+1]]);
    }
    moves.push_back(v);
    
    v.clear();
    for (int i = 8; i < 14; i++)
    {
        v.push_back(arr[r[2*i]][r[2*i+1]]);
    }
    moves.push_back(v);
    
    swap (arr[ox][oy], arr[x2][y2]);
}

void print_moves()
{
    cout << moves.size() << "\n";
    for (vector <int> v : moves)
    {
        cout << v.size();
        for (int x : v)
            cout << " " << x;
        cout << "\n";
    }
}

void gogo()
{
    for (int i = 0; i < N * M; i++)
    {
        int rloc = i / M, cloc = i % M;

        int xloc = -1, yloc = -1;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                if (arr[j][k] == i+1)
                {
                    xloc = j;
                    yloc = k;
                }
            }

        while (yloc != cloc)
        {
            if (yloc < cloc)
            {
                op (xloc, yloc, xloc, yloc + 1);
                yloc++;
            }
            else
            {
                op (xloc, yloc - 1, xloc, yloc);
                yloc--;
            }
        }
        while (xloc != rloc)
        {
            assert (xloc > rloc);
            op (xloc - 1, yloc, xloc, yloc);
            xloc--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            orr[i][j] = arr[i][j];
        }
    }

    gogo();
    if (moves.size() * 14 / 3 > 100000)
    {
        moves.clear();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                arr[i][j] = orr[i][j];
        }

        for (int i = 1; i + 1 < N; i += 2)
        {
            for (int m = 0; m < M; m++)
            {
                vector <int> v;
                for (int j = 0; j < M; j++)
                    v.push_back(arr[i][j]);
                for (int j = M - 1; j >= 0; j--)
                    v.push_back(arr[i+1][j]);
                int nlast = arr[i][0];
                for (int j = 0; j < M; j++)
                {
                    swap (arr[i][j], nlast);
                }
                for (int j = M - 1; j >= 0; j--)
                {
                    swap (arr[i+1][j], nlast);
                }
                arr[i][0] = nlast;
                moves.push_back(v);
            }
        }
        gogo();
    }

    //op (0, 0, 0, 1);
    print_moves();
}