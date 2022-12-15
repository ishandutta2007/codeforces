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

        pair<int, int> cnt[3]{{0, 0}, {0, 1}, {0, 2}};
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(s[i][j] == 'X')
                    cnt[(i + j) % 3].first++;

        sort(cnt, cnt + 3);

        int val = cnt[0].second;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(s[i][j] == 'X' && (i + j) % 3 == val)
                    s[i][j] = 'O';

        for(int i = 0; i < n; ++i)
            cout << s[i] << "\n";
    }
}