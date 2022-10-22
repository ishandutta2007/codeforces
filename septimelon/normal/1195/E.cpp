#include <bits/stdc++.h>
#define MAX 1000000000

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    priority_queue<pii> px; ///max
    ll n, m, a, b, g, x, y, z;
    cin >> n >> m >> a >> b >> g >> x >> y >> z;
    vector<vector<int>> q(n, vector<int>(m));
    q[0][0] = g;
    for (int j = 1; j < m; j++) {
        q[0][j] = ((ll)q[0][j-1] * x + y) % z;
    }
    for (int i = 1; i < n; i++) {
        q[i][0] = ((ll)q[i-1][m-1] * x + y) % z;
        for (int j = 1; j < m; j++) {
            q[i][j] = ((ll)q[i][j-1] * x + y) % z;
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << q[i][j] << " ";
        }
        cout  << endl;
    }*/
    vector<vector<int>> mix(n, vector<int>(m-b+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b-1; j++) {
            px.push(pii(MAX-q[i][j], j));
        }
        for (int j = 0; j < m-b+1; j++) {
            px.push(pii(MAX-q[i][j+b-1], j+b-1));
            while (px.top().second < j)
                px.pop();
            mix[i][j] = MAX - px.top().first;
        }
        while (!px.empty())
            px.pop();
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-b+1; j++) {
            cout << mix[i][j] << " ";
        }
        cout  << endl;
    }*/
    ll ans = 0;
    for (int j = 0; j < m-b+1; j++) {
        for (int i = 0; i < a-1; i++) {
            px.push(pii(MAX-mix[i][j], i));
        }
        for (int i = 0; i < n-a+1; i++) {
            px.push(pii(MAX-mix[i+a-1][j], i+a-1));
            while (px.top().second < i)
                px.pop();
            ans += (ll)(MAX - px.top().first);
        }
        while (!px.empty())
            px.pop();
    }
    cout << ans << endl;
    return 0;
}