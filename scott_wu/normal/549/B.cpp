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
const int MAXN = 110;

int N;
int arr[MAXN];
bool edge[MAXN][MAXN];

vector <int> res;

void fix (int x)
{
    res.push_back (x);
    for (int i = 0; i < N; i++)
        if (edge[x][i])
            arr[i]--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '1')
                edge[i][j] = true;
            else
                edge[i][j] = false;
        }
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    while (true)
    {
        bool good = true;
        for (int i = 0; i < N; i++)
            if (arr[i] == 0)
            {
                good = false;
                fix (i);
                break;
            }
        
        if (good) break;
    }
    
    sort (res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        if (i > 0) cout << " ";
        cout << res[i] + 1;
    }
    cout << "\n";
    return 0;
}