#include <bits/stdc++.h>

using namespace std;

const int k_N = 100 + 3;

int n;
int p[k_N];
pair<int, bool> dp[k_N][k_N][k_N][2];

int solve(int pos, int odd, int even, bool prev = true){
    if(pos == n)
        return 0;

    auto &[answer, solved] = dp[pos][odd][even][prev];
    if(solved)
        return answer;

    answer = k_N;
    solved = true;

    if(p[pos]){
        answer = solve(pos + 1, odd, even, p[pos] & 1);
        if((p[pos] & 1) != prev && pos)
            answer++;
        return answer;
    }

    if(odd){
        if(!prev && pos)
            answer = min(solve(pos + 1, odd - 1, even, true) + 1, answer);
        else
            answer = min(solve(pos + 1, odd - 1, even, true), answer);
    }
    if(even){
        if(prev && pos)
            answer = min(solve(pos + 1, odd, even - 1, false) + 1, answer);
        else
            answer = min(solve(pos + 1, odd, even - 1, false), answer);
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> p[i];

    int cnt_odd, cnt_even;
    cnt_odd = (n + 1) / 2;
    cnt_even = n / 2;

    for(int i = 0; i < n; ++i){
        if(p[i]){
            if(p[i] & 1)
                cnt_odd--;
            else
                cnt_even--;
        }
    }

    cout << solve(0, cnt_odd, cnt_even) << "\n";
}
/*
2
2 0
*/