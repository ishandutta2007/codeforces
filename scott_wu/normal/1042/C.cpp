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
const int MAXN = 200100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    int npos = 0, nneg = 0, nz = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
            nneg++;
        else if (arr[i] > 0)
            npos++;
        else
            nz++;
    }

    int sloc = 0;
    if (npos > 0)
    {
        while (arr[sloc] <= 0) sloc++;
    }
    else if (nneg > 1)
    {
        for (int i = 0; i < N; i++)
            if (arr[i] < arr[sloc]) sloc = i;
    }
    else
    {
        for (int i = 0; i < N; i++)
            if (arr[i] == 0) sloc = i;
    }

    int mskip = -1;
    if (nneg % 2 == 1)
    {
        int bv = 2e9;
        for (int i = 0; i < N; i++)
        {
            if (i == sloc) continue;
            if (arr[i] >= 0) continue;
            if (-arr[i] < bv)
            {
                bv = -arr[i];
                mskip = i;
            }
        }
    }

    if (mskip == -1)
    {
        for (int i = 0; i < N; i++)
            if (arr[i] == 0 && i != sloc) mskip = i;
    }

    for (int i = 0; i < N; i++)
    {
        if (i == sloc) continue;
        if (i == mskip) continue;
        if (arr[i] == 0)
        {
            cout << "1 " << i + 1 << " " << mskip + 1 << "\n";
        }
        else
            cout << "1 " << i + 1 << " " << sloc + 1 << "\n";
    }
    if (mskip != -1)
    {
        cout << "2 " << mskip + 1 << "\n";
    }
}