#include <bits/stdc++.h>

using namespace std;

const int k_N = 12;

pair<int, int> a[k_N], b[k_N];
int cnt_a[k_N], cnt_b[k_N];

int get_common(pair<int, int> x, pair<int, int> y){
    if(x.first == y.first && x.second == y.second)
        return 0;
    if(x.first == y.second && x.second == y.first)
        return 0;

    if(x.first == y.first || x.first == y.second)
        return x.first;
    if(x.second == y.first || x.second == y.second)
        return x.second;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    for(int i = 0; i < m; ++i)
        cin >> b[i].first >> b[i].second;

    int num = 0;
    bool can_know = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int curr_num = get_common(a[i], b[j]);
            if(curr_num){

                if(!cnt_a[i] || cnt_a[i] == curr_num)
                    cnt_a[i] = curr_num;
                else
                    can_know = false;

                if(!cnt_b[j] || cnt_b[j] == curr_num)
                    cnt_b[j] = curr_num;
                else
                    can_know = false;

                if(num && num != curr_num)
                    num = -1;
                else
                    num = curr_num;
            }
        }
    }

    if(num > 0){
        cout << num << "\n";
        return 0;
    }

    if(can_know)
        cout << "0\n";
    else
        cout << "-1\n";

    return 0;
}