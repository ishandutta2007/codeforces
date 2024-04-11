#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M, L;
ll a[MAXN];

int ctot;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> M >> L;
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    ctot = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] <= L && a[i+1] > L)
            ctot++;
    }

    for (int i = 0; i < M; i++)
    {
        int t; cin >> t;
        if (t)
        {
            int p, d;
            cin >> p >> d;
            if (a[p] <= L && a[p] + d > L)
            {
                if (a[p-1] <= L)
                    ctot++;
                if (p < N && a[p+1] > L)
                    ctot--;
            }
            a[p] += d;
        }
        else
        {
            cout << ctot << "\n";
        }
    }
}