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

int N, arr[110];
map <int, int> A, B;
int res[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        A[arr[i]]++;
    }

    int acount = 0;
    for (auto pp : A)
        if (pp.second == 1) acount++;

    for (int i = 0; i < N; i++)
    {
        int cval = arr[i];
        if (acount > 1)
        {
            if (A[cval] == 1)
            {
                res[i] = 1;
                A.erase(cval);
                B[cval]++;
                acount -= 2;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        int cval = arr[i];
        if (res[i] == 0 && acount)
        {
            if (A[cval] > 2)
            {
                res[i] = 1;
                B[cval]++;
                acount--;
            }
        }
    }
    
    if (acount)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        cout << (char) ('A' + res[i]);
    }
    cout << "\n";
}