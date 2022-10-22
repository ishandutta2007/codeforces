#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[100002];
    for(int i = 0; i < n; i++){
        int s, r;
        cin >> s >> r;
        s--;
        v[s].push_back(r);
    }
    for(int i = 0; i < m; i++) sort(v[i].begin(), v[i].end(), greater<int>());
    int r[100002];
    for(int i = 0; i < m; i++){
        int s = 0, j = 0;
        for(; j < (int)v[i].size(); j++){
            s += v[i][j];
            if(s < 0) break;
        }
        r[i] = j;
    }
    P p[100002];
    for(int i = 0; i < m; i++) p[i] = P(r[i], i);
    sort(p, p + m);
    int s[100002]{0};
    int sum = 0, ans = 0, l = 0;
    for(int k = 1; k <= n; k++){
        for(; l < m && p[l].first < k; l++) sum -= s[l];
        for(int i = l; i < m; i++){
            s[i] += v[p[i].second][k - 1];
            sum += v[p[i].second][k - 1];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}