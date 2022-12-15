#include <bits/stdc++.h>

using namespace std;

const int k_N = 1000 +3;

int n, m;
string s[k_N];
int row_prefix[k_N][k_N], column_prefix[k_N][k_N];
bool row_covered[k_N], column_covered[k_N];

bool visited[k_N][k_N];

void dfs(int x, int y){
    visited[x][y] = true;

    array<pair<int, int>, 4> adjacent{pair{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
    for(auto to: adjacent){
        if(to.first < 0 || to.first > n - 1 || to.second < 0 || to.second > m - 1 || visited[to.first][to.second] || s[to.first][to.second] == '.')
            continue;

        dfs(to.first, to.second);
    }
}

int get_row_sum(int row, int l, int r){
    if(l == 0)
        return row_prefix[row][r];

    return row_prefix[row][r] - row_prefix[row][l - 1];
}

int get_column_sum(int column, int l, int r){
    if(l == 0)
        return column_prefix[r][column];

    return column_prefix[r][column] - column_prefix[l - 1][column];
}

void preprocess(){
    for(int i = 0; i < n; ++i){ 
        row_prefix[i][0] = (s[i][0] == '#');
        for(int j = 1; j < m; ++j)
            row_prefix[i][j] = row_prefix[i][j - 1] + (s[i][j] == '#');
    }

    for(int j = 0; j < m; ++j){
        column_prefix[0][j] = (s[0][j] == '#');
        for(int i = 1; i < n; ++i)
            column_prefix[i][j] = column_prefix[i - 1][j] + (s[i][j] == '#');
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> s[i];

    preprocess();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '#'){
                if(i >= 1 && s[i - 1][j] == '.' && get_column_sum(j, 0, i - 1)){
                    cout << "-1\n";
                    return 0;
                }
                if(i <= n - 2 && s[i + 1][j] == '.' && get_column_sum(j, i + 1, n -1)){
                    cout << "-1\n";
                    return 0;
                }
                if(j >= 1 && s[i][j - 1] == '.' && get_row_sum(i, 0, j - 1)){
                    cout << "-1\n";
                    return 0;
                }
                if(j <= m - 2 && s[i][j + 1] == '.' && get_row_sum(i, j + 1, m - 1)){
                    cout << "-1\n";
                    return 0;
                }
                row_covered[i] = true;
                column_covered[j] = true;
            }
            else{
                if(!get_row_sum(i, 0, m - 1) && !get_column_sum(j, 0, n - 1)){
                    row_covered[i] = true;
                    column_covered[j] = true;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(!row_covered[i]){
            cout << "-1\n";
            return 0;
        }
    }

    for(int j = 0; j < m; ++j){
        if(!column_covered[j]){
            cout << "-1\n";
            return 0;
        }
    }

    int answer = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] && s[i][j] == '#'){
                dfs(i, j);
                ++answer;
            }
        }
    }

    cout << answer << "\n";
}