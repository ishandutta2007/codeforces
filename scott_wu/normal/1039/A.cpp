#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll T;
ll val[MAXN];
int arr[MAXN];
ll res[MAXN];

void lose()
{
    cout << "No\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> T;
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }

    int cc = -1;
    for (int i = 0; i < N; i++)
    {
        if (i <= cc)
        {
            if (arr[i] != cc)
                lose();
        }
        else
        {
            if (arr[i] < i)
                lose();
            cc = arr[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > i)
        {
            res[i] = val[i+1];
        }
        else
        {
            if (i > 0 && arr[i-1] == i)
            {
                if (i < N - 1 && val[i+1] - val[i] == 1)
                    lose();
                res[i] = val[i] + 1;
            }
            else
                res[i] = val[i];
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < N; i++)
        cout << res[i] + T << " ";
    cout << "\n";
}