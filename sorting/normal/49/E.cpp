#include <bits/stdc++.h>

using namespace std;

const int k_N = 50 + 3;
const int k_Char = 26 + 3;
const int k_Inf = 1e9;

string s[2], sub[k_N];
vector<pair<int, int>> adjacent[k_N];
int n;

pair<bool, bool> can_make_substring[k_N][k_N][k_Char][2];
pair<int, bool> min_letters[k_N][k_N];

bool check_can_make_substring(int left, int right, int letter_idx, bool string_idx){
    if(left > right)
        return false;

    if(left == right)
        return letter_idx == s[string_idx][left] - 'a';

    auto &[answer, solved] = can_make_substring[left][right][letter_idx][string_idx];
    if(solved)
        return answer;

    solved = true;
    answer = false;

    for(auto to: adjacent[letter_idx]){
        for(int split = left; split < right; ++split){
            bool can_make_left_part = check_can_make_substring(left, split, to.first, string_idx);
            bool can_make_right_part = check_can_make_substring(split + 1, right, to.second, string_idx);

            if(can_make_left_part && can_make_right_part)
                return answer = true;
        }
    }

    return answer;
}

int get_min_letters(array<int, 2> pos){
    bool is_at_end[2];
    is_at_end[0] = (pos[0] == s[0].size());
    is_at_end[1] = (pos[1] == s[1].size());

    if(is_at_end[0] || is_at_end[1])
        return (is_at_end[0] && is_at_end[1]) ? 0 : k_Inf;

    auto &[answer, solved] = min_letters[pos[0]][pos[1]];
    if(solved)
        return answer;

    solved = true;
    answer = k_Inf;

    array<int, 2> new_pos;
    for(new_pos[0] = pos[0] + 1; new_pos[0] <= s[0].size(); ++new_pos[0]){
        for(new_pos[1] = pos[1] + 1; new_pos[1] <= s[1].size(); ++new_pos[1]){
            for(int letter_idx = 0; letter_idx < 26; ++letter_idx){

                if(!check_can_make_substring(pos[0], new_pos[0] - 1, letter_idx, 0))
                    continue;
                if(!check_can_make_substring(pos[1], new_pos[1] - 1, letter_idx, 1))
                    continue;

                answer = min(get_min_letters(new_pos) + 1, answer);
                break;
            }
        }
    }

    return answer;
}

void solve(){
    int answer = get_min_letters({0, 0});
    if(answer >= k_Inf)
        answer = -1;

    cout << answer << "\n";
}

void build_adjacent(){
    for(int i = 0; i < n; ++i)
        adjacent[sub[i][0] - 'a'].push_back({sub[i][3] - 'a', sub[i][4] - 'a'});
}

void read(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s[0] >> s[1];
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> sub[i];
}

int main(){
    read();
    build_adjacent();
    solve();
}