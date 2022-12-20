#include <bits/stdc++.h>

using namespace std;

const int k_N = 4e5 + 3;

int a[k_N], n;
int cnt[k_N], s_cnt[k_N], c_cnt[k_N];
vector<int> v[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    int curr_cnt = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] != a[i - 1]){
            cnt[curr_cnt]++;
            v[curr_cnt].push_back(a[i - 1]);
            curr_cnt = 1;
        }
        else
            curr_cnt++;
    }
    cnt[curr_cnt]++;
    v[curr_cnt].push_back(a[n - 1]);

    for(int i = k_N - 2; i >= 1; --i)
        c_cnt[i] = c_cnt[i + 1] + cnt[i];

    for(int i = 1; i < k_N; ++i)
        s_cnt[i] = s_cnt[i - 1] + i * cnt[i];

    for(int i = n; i >= 1; --i){
        int big_d = 1;
        for(int j = 2; j * j <= i; ++j)
            if(i % j == 0)
                big_d = j;

        int curr = c_cnt[big_d + 1] * big_d + s_cnt[big_d];
        if(curr >= i){
            cout << i << "\n";
            int a = big_d, b =  i / big_d;
            vector<int> nums;
            for(int j = k_N - 1; j >= 0; --j)
                for(int x: v[j])
                    for(int k = 0; k < min(j, a); ++k)
                        nums.push_back(x);

            int x = 0, y = 0;
            vector<vector<int>> rect(a, vector<int>(b));
            for(int j = 0; j < i; ++j){
                rect[x][y] = nums[j];
                if(j == i - 1)
                    break;
                x++;
                if(x == a) x = 0;
                y++;
                if(y == b) y = 0;
                while(rect[x][y]){
                    y++;
                    if(y == b) y = 0;
                }
            }

            //everse(nums.begin(), nums.begin() + i);

            //cout << "nums: ";
            //for(int x: nums)
            //    cout << x << " ";
            //cout << "\n";

            cout << a << " " << b << "\n";
            for(int j = 0; j < a; ++j){
                for(int k = 0; k < b; ++k)
                    cout << rect[j][k] << " ";
                cout << "\n";
            }

            return 0;
        }
    }
}