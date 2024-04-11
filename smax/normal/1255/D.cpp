#include <bits/stdc++.h>
using namespace std;

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1};

int r, c, k;
string grid[100];
unordered_map<char, int> cnt;

//void dfs(int i, int j, char ch) {
//    if (cnt[ch] == 0 || i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '.' && grid[i][j] != '$')
//        return;
//    if (grid[i][j] == '$')
//        cnt[ch]--;
//    grid[i][j] = ch;
//    for (int d=0; d<4; d++)
//        dfs(i + dr[d], j + dc[d], ch);
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int numRice = 0;
        cin >> r >> c >> k;
        for (int i=0; i<r; i++) {
            cin >> grid[i];
            for (int j=0; j<c; j++)
                if (grid[i][j] == 'R')
                    numRice++;
        }

        int di = numRice / k, rm = numRice % k;
        vector<char> chickens;
        for (char ch='0'; ch<='9' && k>0; ch++) {
            chickens.push_back(ch);
            cnt[ch] = di + (rm > 0);
            k--, rm--;
        }
        for (char ch='a'; ch<='z' && k>0; ch++) {
            chickens.push_back(ch);
            cnt[ch] = di + (rm > 0);
            k--, rm--;
        }
        for (char ch='A'; ch<='Z' && k>0; ch++) {
            chickens.push_back(ch);
            cnt[ch] = di + (rm > 0);
            k--, rm--;
        }

        int pos = 0;
        for (int i=0; i<r && pos<chickens.size(); i++) {
            if (i % 2 == 0)
                for (int j=0; j<c && pos<chickens.size(); j++) {
                    if (grid[i][j] == '.')
                        grid[i][j] = chickens[pos];
                    else if (grid[i][j] == 'R') {
                        grid[i][j] = chickens[pos];
                        cnt[chickens[pos]]--;
                        if (cnt[chickens[pos]] == 0)
                            pos++;
                    }
                }
            else
                for (int j=c-1; j>=0 && pos<chickens.size(); j--) {
                    if (grid[i][j] == '.')
                        grid[i][j] = chickens[pos];
                    else if (grid[i][j] == 'R') {
                        grid[i][j] = chickens[pos];
                        cnt[chickens[pos]]--;
                        if (cnt[chickens[pos]] == 0)
                            pos++;
                    }
                }
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j] == '.')
                    grid[i][j] = (i > 0 ? grid[i-1][j] : grid[i][j-1]);
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}