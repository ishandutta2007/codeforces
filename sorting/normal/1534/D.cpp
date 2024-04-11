#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }

const int N = 2000 + 3;

int n;
int quer_ans[N], d[N];
vector<pair<int, int>> ans;

void query(int u){
    cout << "? " << u << "\n";
    cout.flush();
    for(int i = 1; i <= n; ++i)
        cin >> quer_ans[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    query(1);
    for(int i = 1; i <= n; ++i)
        d[i] = quer_ans[i];

    int cnt[2] = {0, 0};
    for(int i = 1; i <= n; ++i)
        cnt[d[i] & 1]++;

    int ch = (cnt[0] > cnt[1]);
    if(ch == 0){
        for(int i = 1; i <= n; ++i)
            if(d[i] == 1)
                ans.push_back({1, i});
    }

    for(int i = 2; i <= n; ++i){
        if((d[i] & 1) == ch){
            query(i);
            for(int j = 1; j <= n; ++j)
                if(quer_ans[j] == 1)
                    ans.push_back({i, j});
        }
    }

    cout << "!\n";
    cout.flush();
    for(int i = 0; i < n - 1; ++i)
        cout << ans[i].first << " " << ans[i].second << "\n";
    cout.flush();
}