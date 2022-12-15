#include <bits/stdc++.h>

using namespace std;

const int k_N = 500 + 3;

int n, x0, y0;
bool is_lit[k_N][k_N], visited[k_N][k_N];
map<pair<int, int>, char> direction_char;
string instructions = "";

bool find_lit_light(int x, int y, pair<int, int> direction){
    int new_x = x + direction.first;
    int new_y = y + direction.second;

    if(new_x < 1 || new_y < 1 || new_x > n || new_y > n)
        return false;
    if(visited[new_x][new_y])
        return false;

    if(is_lit[new_x][new_y])
        return true;

    return find_lit_light(new_x, new_y, direction);
}

void dfs(int x, int y, pair<int, int> previous_direction);

void try_to_go_in_direction(int x, int y, pair<int, int> direction){
    if(find_lit_light(x, y, direction)){
        instructions += direction_char[direction];
        dfs(x + direction.first, y + direction.second, direction);
    }
}

void dfs(int x, int y, pair<int, int> previous_direction){
    visited[x][y] = true;

    if(!is_lit[x][y]){
        is_lit[x][y] = true;
        instructions += "1";
    }

    pair<int, int> direction;

    

    if(!previous_direction.first)
        direction = {1, 0};
    else
        direction = {0, 1};

    try_to_go_in_direction(x, y, direction);

    direction.first = -direction.first;
    direction.second = -direction.second;

    try_to_go_in_direction(x, y, direction);

    direction = previous_direction;

    try_to_go_in_direction(x, y, direction);

    direction.first = -previous_direction.first;
    direction.second = -previous_direction.second;

    if(x0 == x && y0 == y)
        try_to_go_in_direction(x, y, direction);

    instructions += "2";
    is_lit[x][y] = false;

    if(x0 != x || y0 != y)
        instructions += direction_char[direction];
}

bool build_instructions(){
    dfs(x0, y0, {1, 0});

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(is_lit[i][j])
                return false;

    return true;
}

void build_direction_char(){
    direction_char[{0, -1}] = 'L';
    direction_char[{0, 1}] = 'R';
    direction_char[{-1, 0}] = 'U';
    direction_char[{1, 0}] = 'D';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x0 >> y0;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> is_lit[i][j];

    build_direction_char();
    bool has_solution = build_instructions();

    if(!has_solution){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << instructions << "\n";

    return 0;
}