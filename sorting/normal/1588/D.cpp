#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 10 + 3;
const int INF = 1e9;

int n;
string s[N];
int pos[52][N][2];
pair<array<int, 3>, bool> dp[52][(1 << 10) + 3];

int get_idx(char c){
    if('a' <= c  && c <= 'z') return c - 'a';
    return (c - 'A') + 26;
}

char get_ch(int idx){
    if(idx < 26) return 'a' + idx;
    return 'A' + (idx - 26);
}

int get_dp(int ch, int state){
    auto &[p, solved] = dp[ch][state];
    auto &[ans, next_ch, next_state] = p;
    if(solved)
        return ans;
    
    solved = true;
    ans = 0;
    next_ch = -1;
    next_state = -1;

    for(int i = 0; i < n; ++i)
        if(pos[ch][i][((state >> i) & 1)] == -1){
            ans = -INF;
            return ans;
        }

    for(int new_ch = 0; new_ch < 52; ++new_ch){
        int new_state = 0;
        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(pos[new_ch][i][0] > pos[ch][i][((state >> i) & 1)])
                continue;
            if(pos[new_ch][i][1] > pos[ch][i][((state >> i) & 1)]){
                new_state += (1 << i);
                continue;
            }
            ok = false;
            break;
        }
        if(!ok) continue;

        int cand = get_dp(new_ch, new_state) + 1;
        if(cand > ans){
            ans = cand;
            next_ch = new_ch;
            next_state = new_state;
        }
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    for(int i = 0; i < 52; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < 2; ++k)
                pos[i][j][k] = -1;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < s[i].size(); ++j){
            if(pos[get_idx(s[i][j])][i][0] == -1)
                pos[get_idx(s[i][j])][i][0] = j;
            else
                pos[get_idx(s[i][j])][i][1] = j;
        }
    }

    for(int i = 0; i < 52; ++i)
        for(int j = 0; j < (1 << n); ++j)
            dp[i][j].second = false;

    int ans = 0, ch = -1;
    for(int i = 0; i < 52; ++i){
        int cand = get_dp(i, 0) + 1;
        if(cand > ans){
            ans = cand;
            ch = i;
        }
    }
    cout << ans << "\n";
    if(!ans){
        cout << "\n";
        return;
    }

    int state = 0;
    while(true){
        cout << get_ch(ch);
        --ans;
        if(!ans) break;
        int new_ch = dp[ch][state].first[1];
        int new_state = dp[ch][state].first[2];
        ch = new_ch;
        state = new_state;
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}