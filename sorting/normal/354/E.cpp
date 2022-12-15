#include <bits/stdc++.h>

using namespace std;

pair<bool, int> dp[60 + 1][6 + 1];
int numbers[60 + 1][6 + 1];

string answer[6];

bool recurse(const string &n, int position, int remainder){
    if(position == -1)
        return !remainder;

    int expected = n[position] - '0';
    int add = 0;

    add = expected + 10 - (remainder % 10);
    add %= 10;

    for(int i = add; i <= 42; i += 10){
        if(!dp[i][6].first)
            continue;

        if(recurse(n, position - 1, (remainder + i - expected) / 10)){
            for(int j = 0; j < 6; ++j)
                answer[j] += numbers[i][j] + '0';

            return true;
        }
    }

    return false;
}

void build_dp(){
    for(int i = 0; i < 60; ++i){
        for(int j = 0; j <= 6; ++j){
            if(j == 0){
                if(i == 0)
                    dp[i][j] = {true, -1};
                else
                    dp[i][j] = {false, -1};
                continue;
            }

            if(dp[i][j - 1].first){
                dp[i][j] = {true, 0};
                continue;
            }

            if(i >= 4 && dp[i - 4][j - 1].first){
                dp[i][j] = {true, 4};
                continue;
            }

            if(i >= 7 && dp[i - 7][j - 1].first){
                dp[i][j] = {true, 7};
                continue;
            }

            dp[i][j] = {false, -1};
        }
    }

    for(int i = 0; i <= 60; ++i){
        if(dp[i][6].first){
            int curr = i, cnt = 6;
            while(cnt != 0){
                numbers[i][cnt - 1] = dp[curr][cnt].second;
                curr -= dp[curr][cnt].second;
                --cnt; 
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    build_dp();

    int t;
    cin >> t;

    while(t--){
        string n;
        cin >> n;

        for(int i = 0; i < 6; ++i)
            answer[i] = "";

        if(!recurse(n, n.size() - 1, 0)){
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < 6; ++i){
            int mx = -1;
            for(int j = 0; j < (int)answer[i].size() - 1; ++j){
                if(answer[i][j] != '0')
                    break;

                mx = j;
            }

            if(mx != -1)
                answer[i].erase(0, mx + 1);
        }
    
        for(int i = 0; i < 6; ++i)
            cout << answer[i] << " ";
        cout << "\n";
    }
}