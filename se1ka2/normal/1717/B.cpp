#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        r--;
        c--;
        char ans[505][505];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i + j) % k == (r + c) % k)
                {
                    ans[i][j] = 'X';
                }
                else
                {
                    ans[i][j] = '.';
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
}