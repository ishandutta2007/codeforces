#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int N, M;
string s[2100];
int t[2100];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    
    for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    if (s[i][j] == '1')
    t[j]++;
    
    bool f = false;
    for (int i = 0; i < N; i++)
    {
        bool good = true;
        for (int j = 0; j < M; j++)
            if (s[i][j] == '1' && t[j] == 1)
                good = false;
        if (good) f = true;
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
}