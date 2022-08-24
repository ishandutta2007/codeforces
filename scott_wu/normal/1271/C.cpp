#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int xc[4] = {-1, 1, 0, 0};
int yc[4] = {0, 0, -1, 1};
int nc[4];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int N, X, Y;
    cin >> N >> X >> Y;

    for (int i = 0; i < 4; i++)
        nc[i] = 0;

    for (int t = 0; t < N; t++)
    {
        int X2, Y2;
        cin >> X2 >> Y2;

        int goal = abs (X - X2) + abs (Y - Y2);
        for (int i = 0; i < 4; i++)
        {
            int Xn = X + xc[i], Yn = Y + yc[i];
            if (abs (X - Xn) + abs (Xn - X2) + abs (Y - Yn) + abs (Yn - Y2) == goal)
                nc[i]++;
        }
    }

    int gloc = 0;
    for (int i = 1; i < 4; i++)
        if (nc[i] > nc[gloc])
            gloc = i;
    cout << nc[gloc] << "\n";
    cout << X + xc[gloc] << " " << Y + yc[gloc] << "\n";
}