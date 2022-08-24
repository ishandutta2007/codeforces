#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int N, M;
int board[150][150];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;

    int xx = 0, yy = 0, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char ch; cin >> ch;
            board[i][j] = (ch == 'B');
            if (board[i][j])
            {
                xx += i;
                yy += j;
                cnt++;
            }
        }
    }

    xx /= cnt;
    yy /= cnt;
    cout << xx + 1 << " " << yy + 1 << "\n";
}