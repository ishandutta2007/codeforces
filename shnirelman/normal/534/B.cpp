#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 1000000;

int main(){
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    vector<vector<int> > dp(t, vector<int>(10012, -INF));
    vector<vector<bool> > used(t, vector<bool>(10012, false));
    dp[0][v1] = v1;
    used[0][v1] = true;

    queue<pair<int, int> > q;
    q.push(make_pair(0, v1));

    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();
        if(a >= t - 1)break;

        for(int i = b - d; i <= b + d; i++)
            if(i >= 0){
                //cout << a << ' ' << b << ' ' << i << endl;
                dp[a + 1][i] = max(dp[a + 1][i], dp[a][b] + i);
                if(!used[a + 1][i])q.push(make_pair(a + 1, i));
                used[a + 1][i] = true;

            }
    }

    cout << dp[t - 1][v2];
}