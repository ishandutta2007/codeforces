#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e4 + 3;

int n, m, p;
int x[k_N], y[k_N];
int dp[2][k_N];

inline int f(int a, int b){
    int curr = x[a] + y[b];
    return curr >= p ? curr - p : curr;
}

void solve(int l, int r, int sl, int sr){
    if(l == r){
        if(l == 0 && r == n){
            int answer = 0;
            for(int i = 0; i <= m; ++i)
                answer += f(0, i);
            cout << answer << "\n";
        }
        for(int i = 0; i < sr - sl; ++i)
            cout << "S";
        return;
    }

    int mid = (l + r) >> 1;
    static int first_part[k_N], second_part[k_N];

    for(int i = r; i >= mid + 1; --i){
        for(int j = sr; j >= sl; --j){
            int &answer = dp[i & 1][j];
            answer = 0;
            if(i != r)
                answer = max(dp[(i + 1) & 1][j], answer);
            if(j != sr)
                answer = max(dp[i & 1][j + 1], answer);
            answer += f(i, j);
        }
    }

    for(int i = sr; i >= sl; --i)
        first_part[i] = dp[(mid + 1) & 1][i];

    for(int i = l; i <= mid; ++i){
        for(int j = sl; j <= sr; ++j){
            int &answer = dp[i & 1][j];
            answer = 0;
            if(i != l)
                answer = max(dp[(i - 1) & 1][j], answer);
            if(j != sl)
                answer = max(dp[i & 1][j - 1], answer);
            answer += f(i, j);
        }
    }

    for(int i = sr; i >= sl; --i)
        second_part[i] = dp[mid & 1][i];

    int best_score = 0, best_idx = sr;
    for(int i = sr; i >= sl; --i){
        int curr = first_part[i] + second_part[i];
        if(curr > best_score){
            best_score = curr;
            best_idx = i;
        }
    }

    if(l == 0 && r == n)
        cout << best_score << "\n";

    solve(l, mid, sl, best_idx);
    cout << "C";
    solve(mid + 1, r, best_idx, sr);
}

void read(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    n--;
    m--;

    for(int i = 0; i <= n; ++i){
        cin >> x[i];
        x[i] %= p;
    }
    for(int i = 0; i <= m; ++i){
        cin >> y[i];
        y[i] %= p;
    }
}

int main(){
    read();
    solve(0, n, 0, m);
    cout << "\n";
}