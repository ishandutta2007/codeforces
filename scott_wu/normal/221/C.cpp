#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int num[MAXN];
int snum[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        snum[i] = num[i];
    }
    
    sort (snum, snum + N);
    
    int val = 0;
    for (int i = 0; i < N; i++)
        if (num[i] != snum[i])
            val++;
    
    if (val <= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    //system ("Pause");
    return 0;
}