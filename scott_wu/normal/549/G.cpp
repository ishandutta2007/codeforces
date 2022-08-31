#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i] += i;
    }
    
    sort (arr, arr + N);
    
    bool good = true;
    for (int i = 0; i < N - 1; i++)
        if (arr[i] == arr[i+1])
            good = false;
    
    if (!good)
        cout << ":(\n";
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (i > 0) cout << " ";
            cout << arr[i] - i;
        }
        cout << "\n";
    }
    
    return 0;
}