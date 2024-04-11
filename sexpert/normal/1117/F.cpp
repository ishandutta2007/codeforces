#include <bits/stdc++.h>
using namespace std;

const int MAXP = 17;
const int INF = 1e9;

vector<int> msk[MAXP][MAXP];
int good[MAXP][MAXP], vis[MAXP][MAXP][1<<MAXP], bad[1 << MAXP];
int memo[1<<MAXP], cnt[MAXP], n, p;
queue<int> q[MAXP][MAXP];

int dp(int mask) {
    if(memo[mask] != -1)
        return memo[mask];
    if(bad[mask]) {
        //cout << mask << " " << INF << endl;
        return memo[mask] = INF;
    }
    int x = 0;
    for(int i = 0; i < p; i++)
        if(mask & (1 << i))
            x += cnt[i];
    memo[mask] = x;
    for(int i = 0; i < p; i++) {
        if(mask & (1 << i))
            memo[mask] = min(memo[mask], dp(mask ^ (1 << i)));
    }
    //cout << mask << " " << memo[mask] << endl;
    return memo[mask];
}

int main() {
    string s;
    cin >> n >> p;
    cin >> s;

    for(int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    for(int i = 0; i < p; i++)
        for(int j = 0; j < p; j++)
            cin >> good[i][j];

    for(int i = 0; i < p; i++) {
        for(int j = 0; j < p; j++) {
            if(i == j && cnt[i] < 2)
                continue;
            if(cnt[i] == 0 || cnt[j] == 0)
                continue;
            if(good[i][j])
                continue;
            int ma = 0, ex = ((1 << i) | (1 << j));
            //cout << i << " " << j << " " << ex << endl;
            bool si = false;
            for(int pos = 0; pos < n; pos++) {
                int di = s[pos] - 'a';
                if(di == i || di == j) {
                    if(i == j) {
                        if(!si) {
                            si = true;
                            ma = 0;
                            continue;
                        }
                        if(!vis[i][j][((1 << p) - 1 - ma)|ex]) {
                            q[i][j].push(((1 << p) - 1 - ma) | ex);
                            vis[i][j][((1 << p) - 1 - ma)|ex] = 1;
                            //cout << i << " " << j << " " << (((1 << p) - 1 - ma)|ex) << " " << ex << endl;
                        }
                        ma = 0;
                        continue;
                    }
                    if(di == i && !si) {
                        si = true;
                        ma = 0;
                        continue;
                    }
                    if(di == j) {
                        if(si) {
                            //if(i == 2 && j == 3)
                            //    cout << "duuuude: " << ma << endl;
                            if(!vis[i][j][((1 << p) - 1 - ma)|ex]) {
                                //cout << "goi";
                                q[i][j].push(((1 << p) - 1 - ma)|ex);
                                vis[i][j][((1 << p) - 1 - ma)|ex] = 1;
                                //cout << i << " " << j << " " << (((1 << p) - 1 - ma)|ex) << " " << ex << endl;
                            }
                        }
                        si = false;
                    }
                    ma = 0;
                }
                else {
                    if(si)
                        ma |= (1 << di);
                }
            }
        }
    }
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < p; j++) {
            while(!q[i][j].empty()) {
                int ma = q[i][j].front();
                q[i][j].pop();
                bad[ma] = 1;
                for(int k = 0; k < p; k++) {
                    if(k == i || k == j)
                        continue;
                    //if(i == 2 && j == 3)
                    //    cout << "here: " << ma << endl;
                    if(ma & (1 << k)) {
                        int mo = ma ^ (1 << k);
                        if(!vis[i][j][mo]) {
                            q[i][j].push(mo);
                            vis[i][j][mo] = 1;
                        }
                    }
                }
            }
        }
    }
    //for(int i = 0; i < (1 << p); i++)
    //    if(bad[i])
    //        cout << i << endl;
    memset(memo, -1, sizeof memo);
    cout << dp((1 << p) - 1) << endl;
}