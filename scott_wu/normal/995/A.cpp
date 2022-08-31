#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 55;

int N, K;
int board[4][MAXN];

vector <pair <int, pair <int, int> > > v;
pair <int, int> ord[2*MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
    {
        ord[i] = make_pair (1, i);
        ord[i+N] = make_pair (2, N - 1 - i);
    }
    ord[2*N] = make_pair (1, 0);

    for (int run = 0; run < 400; run++)
    {
        bool found = false;
        for (int i = 0; i < 2 * N; i++)
        {
            int x = ord[i].first, y = ord[i].second;
            if (board[x][y] > 0 && board[x][y] == board[x^1][y])
            {
                v.push_back(make_pair (board[x][y], make_pair (x^1, y)));
                board[x][y] = 0;
                found = true;
            }
        }

        int mv = 0;
        for (int i = 2 * N - 1; i >= mv; i--)
        {
            int x = ord[i].first, y = ord[i].second;
            int nx = ord[i+1].first, ny = ord[i+1].second;
            if (board[x][y] > 0 && board[nx][ny] == 0)
            {
                v.push_back(make_pair (board[x][y], make_pair (nx, ny)));
                swap (board[x][y], board[nx][ny]);
                found = true;
                if (i == 2 * N - 1)
                    mv = 1;
            }
        }

        if (!found)
            break;
    }

    bool bad = false;
    for (int i = 1; i <= 2; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j])
                bad = true;

    if (bad)
    {
        cout << "-1\n";
        return 0;
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second.first + 1 << " " << v[i].second.second + 1 << "\n";
    }
}