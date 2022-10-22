#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[j][i];
    int ans = 0;
    for(int j = 0; j < m; j++){
        vector<int> d(n);
        for(int i = 0; i < n; i++){
            if(((m * i + (j + 1)) - a[j][i] + m * n) % m == 0 && a[j][i] <= m * n) d[((m * i + (j + 1)) - a[j][i] + m * n) / m % n]++;
        }
        int s = INF;
        for(int i = 0; i < n; i++) s = min(s, n - d[i] + i);
        ans += s;
    }
    cout << ans << endl;
}