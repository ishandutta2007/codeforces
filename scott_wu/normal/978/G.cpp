#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N, M;
int S[MAXN], D[MAXN], C[MAXN];
int res[MAXN];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> S[i] >> D[i] >> C[i];
        S[i]--;
        D[i]--;
    }

    bool good = true;
    for (int i = 0; i < N; i++)
    {
        bool exam = false;
        for (int j = 0; j < M; j++)
            if (D[j] == i)
            {
                if (C[j] > 0)
                    good = false;
                exam = true;
                break;
            }
        if (exam)
        {
            res[i] = M + 1;
            continue;
        }


        int bex = -1, bval = 1e9;
        for (int j = 0; j < M; j++)
        {
            if (C[j] > 0 && S[j] <= i && D[j] > i)
            {
                if (D[j] < bval)
                {
                    bval = D[j];
                    bex = j;
                }
            }
        }
        if (bex == -1)
        {
            res[i] = 0;
        }
        else
        {
            res[i] = bex + 1;
            C[bex]--;
        }
    }

    if (!good)
        cout << "-1\n";
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}