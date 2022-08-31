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
const int MAXM = 100100;

int N, M;
int d[MAXM], h[MAXM];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> d[i] >> h[i];
    
    int ans = h[0] + d[0] - 1;
    for (int i = 0; i < M - 1; i++)
    {
        if (d[i+1] - d[i] < abs (h[i+1] - h[i]))
        {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        
        int hi = max (h[i+1], h[i]), x = d[i+1] - d[i] - abs (h[i+1] - h[i]);
        
        //cout << hi << " " << x << "\n";
        ans = max (ans, hi + x/2);
    }
    ans = max (ans, h[M-1] + (N - d[M-1]));
    cout << ans << "\n";
    
    return 0;
}