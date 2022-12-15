#include <bits/stdc++.h>

typedef long long ll;
template<typename T> void check_min(T &a, const T b){a = (a < b) ? a : b;}
template<typename T> void check_max(T &a, const T b){a = (a > b) ? a : b;}
using namespace std;

const int N = 4e5 + 3;

int n, a[N][2], pos[N];
bool vis[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i][0] >> a[i][1];
    for(int i = 1; i <= n; ++i){
        pos[a[i][0]] = i;
        pos[a[i][1]] = i;
    }

    int ans = 0, curr_cnt, curr_add;
    int l = 1, r = 2 * n;
    while(l <= r){
        int side = a[pos[r]][1] == r;
        int oth = a[pos[r]][!side];
        bool b = false;
        vector<int> v1, v2;
        for(int i = l; i < oth; ++i)
            v1.push_back(i);
        l = oth + 1;
        r--;
        curr_add = 0;
        curr_cnt = 1;

        while(!v1.empty()){
            if(!b){
                int prev;
                prev = r;

                v2.clear();
                for(int i: v1){
                    int side_i = a[pos[i]][1] == i;
                    int oth = a[pos[i]][!side_i];
                    ++curr_cnt;
                    curr_add += side_i != side;

                    if(oth > prev || vis[pos[i]]){
                        cout << "-1\n";
                        return 0;
                    }
                    vis[pos[i]] = true;
                    for(; prev > oth; --prev)
                        v2.push_back(prev);
                    --prev;
                }
                r = prev;
            }
            else{
                int prev;
                prev = l;

                v2.clear();
                for(int i: v1){
                    int side_i = a[pos[i]][1] == i;
                    int oth = a[pos[i]][!side_i];
                    ++curr_cnt;
                    curr_add += side_i != side;

                    if(oth < prev || vis[pos[i]]){
                        cout << "-1\n";
                        return 0;
                    }
                    vis[pos[i]] = true;
                    for(; prev < oth; ++prev)
                        v2.push_back(prev);
                    ++prev;
                }
                l = prev;
            }
            v1.clear();
            swap(v1, v2);
            b = !b;
        }
        ans += min(curr_add, curr_cnt - curr_add);
    }
    cout << ans << "\n";
}