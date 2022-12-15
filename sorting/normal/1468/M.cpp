#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
const int C = 250;

int n, cnt[N];
vector<int> v[N], pairs[N];
pair<int, int> ans;

void output_ans(){
    pair<int, int> ans2{-1, -1};
    bool found_ans = false;
    for(int i = 0; i < n; ++i){
        for(int x: v[i])
            cnt[x]++;
        if(cnt[ans.first] && cnt[ans.second]){
            if(ans2.first == -1) ans2.first = i + 1;
            else{
                ans2.second = i + 1;
                cout << ans2.first << " " << ans2.second << "\n";
                found_ans = true;
            }
        }
        for(int x: v[i])
            cnt[x]--;
        if(found_ans) return;
    }
}


bool check_big(int i){
    bool found_ans = false;
    for(int x: v[i])
        cnt[x]++;

    for(int j = 0; j < n; ++j){
        if(i == j) continue;
        pair<int, int> same{-1, -1};
        for(int k = 0; k < v[j].size(); ++k){
            int x = v[j][k];
            cnt[x]++;
            if(cnt[x] == 2){
                if(same.first == -1) same.first = x;
                else{
                    same.second = x;
                    ans = same;
                    for(; k >= 0; --k) cnt[v[j][k]]--;
                    found_ans = true;
                    break;
                }
            }
        }
        if(found_ans) break;
        for(int x: v[j])
            cnt[x]--;
    }

    for(int x: v[i])
        cnt[x]--;

    if(found_ans) output_ans();
    return found_ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        v[i].clear();
        int k;
        cin >> k;
        v[i].resize(k);
        for(int &x: v[i]) cin >> x;
    }

    vector<int> numbers;
    for(int i = 0; i < n; ++i)
        for(int x: v[i])
            numbers.push_back(x);

    sort(numbers.begin(), numbers.end());
    numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < v[i].size(); ++j)
            v[i][j] = lower_bound(numbers.begin(), numbers.end(), v[i][j]) - numbers.begin();

    for(int i = 0; i < n; ++i)
        if(v[i].size() >= C)
            if(check_big(i))
                return;

    for(int i = 0; i < n; ++i)
        if(v[i].size() < C)
            for(int j = 0; j < v[i].size(); ++j)
                for(int k = j + 1; k < v[i].size(); ++k){
                    int x = v[i][j], y = v[i][k];
                    if(x > y) swap(x, y);
                    pairs[x].push_back(y);
                }

    vector<int> to_look;
    for(int i = 0; i < n; ++i)
        if(v[i].size() < C)
            for(int x: v[i])
                to_look.push_back(x);

    sort(to_look.begin(), to_look.end());
    to_look.resize(unique(to_look.begin(), to_look.end()) - to_look.begin());

    bool found_ans = false;
    for(int x: to_look){
        for(int i = 0; i < pairs[x].size(); ++i){
            int y = pairs[x][i];
            cnt[y]++;
            if(cnt[y] == 2){
                ans = {x, y};
                for(; i >= 0; --i)
                    cnt[pairs[x][i]]--;
                found_ans = true;
                break;
            }
        }
        if(found_ans) break;
        for(int y: pairs[x])
            cnt[y]--;
    }

    for(int x: to_look)
        pairs[x].clear();

    if(!found_ans) cout << "-1\n";
    else output_ans();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}