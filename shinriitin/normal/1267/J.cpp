#include <bits/stdc++.h>

void read(int &n){
    n = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

const int N = 2000010;

int cnt[N];

void solve(){
    int n;
    read(n);
    for (int i = 0; i < n; ++ i){
        int x;
        read(x);
        ++ cnt[x];
    }
    std::vector <int> have;
    for (int i = 1; i <= n; ++ i){
        if (cnt[i]){
            have.push_back(cnt[i]);
        }
    }
    int min = *std::min_element(have.begin(), have.end());
    int ans = INT_MAX;
    for (int s = 1; s <= min + 1; ++ s){
        int sum = 0;
        bool flag = true;
        for (auto u : have){
            int cnt_s_1 = s - u % s;
            cnt_s_1 -= cnt_s_1 >= s ? s : 0;
            if (1ll * cnt_s_1 * (s - 1) > u){
                flag = false;
                break;
            }
            sum += cnt_s_1 + (u - cnt_s_1 * (s - 1)) / s;
        }
        if (flag){
            ans = std::min(ans, sum);
        }
    }
    for (int i = 0; i <= n; ++ i){
        cnt[i] = 0;
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    read(test);
    while (test --){
        solve();
    }
    return 0;
}

/*
3
11
1 5 1 5 1 5 1 1 1 1 5
6
1 2 2 2 2 1
5
4 3 3 1 2
 */