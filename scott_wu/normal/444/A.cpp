#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 510;

int N, M;
int dist[MAXN][MAXN];
int weight[MAXN];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> weight[i];
    
    double ans = 0.0;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        
        dist[a][b] = dist[b][a] = c;
        
        ans = max (ans, (weight[a] + (double) weight[b]) / ((double) c));
    }

    cout << fixed << setprecision (11) << ans << "\n";
    //system ("Pause");
    return 0;
}