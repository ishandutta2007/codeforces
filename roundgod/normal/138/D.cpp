#include <iostream>
#include <cstring>
using namespace std;
 
#define MAX_N 20
 
int H, W;
char board[MAX_N + 1][MAX_N + 1];
 
int grundy[2 * MAX_N + 1][2 * MAX_N + 1][2 * MAX_N + 1][2 * MAX_N + 1][2];
 
int search(int x_min, int x_max, int y_min, int y_max, int odd)
{
    int &ret = grundy[x_min][x_max][y_min][y_max][odd];
    if (ret != -1) return ret;
 
    char s[MAX_N *2 + 1] = {0};
    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (((x + y) & 1) == odd)
            {
                const int x_ = y + x, y_ = y - x + W;
                if (x_min <= x_ && x_ < x_max && y_min <= y_ && y_ < y_max)
                {
                    const char cell = board[y][x];
                    int g = 0;
                    if (cell == 'L')
                    {// X
                        g = search(x_min, x_, y_min, y_max, odd) ^ search(x_ + 1, x_max, y_min, y_max, odd);
                    }
                    if (cell == 'R')
                    {// Y
                        g = search(x_min, x_max, y_min, y_, odd) ^ search(x_min, x_max, y_ + 1, y_max, odd);
                    }
                    if (cell == 'X')
                    {// XY
                        g = search(x_min, x_, y_min, y_, odd) ^ search(x_min, x_, y_ + 1, y_max, odd) ^
                             search(x_ + 1, x_max, y_min, y_, odd) ^
                             search(x_ + 1, x_max, y_ + 1, y_max, odd);
                    }
                    s[g] = 1;
                }
            }
        }
    }
 
    while (s[++ret]);
    return ret;
}
 
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &H, &W);
    for (int i = 0; i < H; ++i)
    {
        scanf(" %s ", board[i]);
    }
    memset(grundy, -1, sizeof(grundy));
 
    puts(search(0, H + W, 0, H + W, 0) ^ search(0, H + W, 0, H + W, 1) ? "WIN" : "LOSE");
#ifdef LOCAL
    fclose(stdin);
#endif
    return 0;
}