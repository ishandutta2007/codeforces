#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> s(n);
        for(int i = 0; i < n; ++i)
            cin >> s[i];

        pair<int, int> cnt[2][3]{{{0, 0}, {0, 1}, {0, 2}}, {{0, 0}, {0, 1}, {0, 2}}};
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                if(s[i][j] == 'X')
                    cnt[0][(i + j) % 3].first++;
                if(s[i][j] == 'O')
                    cnt[1][(i + j) % 3].first++;
            }

        sort(cnt[0], cnt[0] + 3);
        sort(cnt[1], cnt[1] + 3);

        int val[2]{cnt[0][0].second, cnt[1][0].second};
        if(cnt[0][0].second == cnt[1][0].second){
            if(cnt[0][1].first - cnt[0][0].first < cnt[1][1].first - cnt[1][0].first)
                val[0] = cnt[0][1].second;
            else
                val[1] = cnt[1][1].second;
        }

        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                if(s[i][j] == 'X' && (i + j) % 3 == val[0])
                    s[i][j] = 'O';
                else if(s[i][j] == 'O' && (i + j) % 3 == val[1])
                    s[i][j] = 'X';
            }

        for(int i = 0; i < n; ++i)
            cout << s[i] << "\n";
    }
}