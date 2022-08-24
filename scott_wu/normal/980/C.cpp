#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, K;
int arr[MAXN];
int res[256];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < 256; i++)
        res[i] = -1;
    for (int i = 0; i < N; i++)
    {
        int x = arr[i];
        if (res[x] != -1)
        {
            continue;
        }

        int cstop = x;
        while (cstop > (x - K + 1) && cstop > 0 && res[cstop] == -1)
            cstop--;

        //cout << x << " " << cstop << "\n";

        if (res[cstop] != -1)
        {
            if (res[cstop] + K - 1 >= x)
            {
                for (int i = cstop + 1; i <= x; i++)
                    res[i] = res[cstop];
            }
            else
            {
                for (int i = cstop + 1; i <= x; i++)
                    res[i] = cstop + 1;
            }
        }
        else
        {
            for (int i = cstop; i <= x; i++)
                res[i] = cstop;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << res[arr[i]];
    }
    cout << "\n";
}