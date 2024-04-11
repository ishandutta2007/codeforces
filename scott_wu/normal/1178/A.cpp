#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;

int N;
int arr[110];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    int ctot = 0, stot = 0;
    int np = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        stot += arr[i];
        if (i == 0 || arr[i] * 2 <= arr[0])
        {
            ctot += arr[i];
            np++;
        }
    }

    if (ctot * 2 > stot)
    {
        cout << np << "\n";
        for (int i = 0; i < N; i++)
        {
            if (i == 0 || arr[i] * 2 <= arr[0])
            {
                if (i) cout << " ";
                cout << i + 1;
            }
        }
        cout << "\n";
    }
    else
        cout << "0\n";
}