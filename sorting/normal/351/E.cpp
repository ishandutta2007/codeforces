#include <bits/stdc++.h>

using namespace std;

const int k_N = 2000 + 3;
const int k_Value = 1e5 + 3;//

int a[k_N], n;
vector<int> positions[k_Value];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] = abs(a[i]);

        positions[a[i]].push_back(i);
    }

    long long answer = 0;
    int cnt = n;

    for(int value = k_Value - 1; value >= 0; --value){
        cnt -= positions[value].size();

        int prev = 0;
        int l_cnt = 0, r_cnt = cnt;
        for(int position: positions[value]){
            for(; prev < position; ++prev){
                if(a[prev] < value){
                    ++l_cnt;
                    --r_cnt;
                }
            }

            answer += min(l_cnt, r_cnt);
            //cout << l_cnt << " " << r_cnt << " - " << position << endl; 
        }
    }

    cout << answer << "\n";
}