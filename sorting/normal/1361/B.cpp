#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e6 + 7;
const long long k_Mod = 1e9 + 7;

int n, p;
int k[k_N], cnt[k_N];

long long fast_pow(long long base, long long exp){
    if(!exp)
        return 1;
    if(exp & 1)
        return base * fast_pow(base, exp ^ 1) % k_Mod;

    long long t = fast_pow(base, exp >> 1);
    return t * t % k_Mod;
}

void solve_test(){
    cin >> n >> p;

    for(int i = 0; i < n; ++i)
        cin >> k[i];

    long long answer = 0;
    long long cnt = 0;

    int pr;
    sort(k, k + n);
    pr = k[n - 1];

    for(int i = n - 1; i >= 0; --i){
        if(cnt && p != 1){
            for(int j = 0; j < pr - k[i] && cnt < k_N; ++j)
                cnt *= p;
        }

        if(!cnt){
            cnt++;
            answer += fast_pow(p, k[i]);
            if(answer >= k_Mod)
                answer += k_Mod;
        }
        else{
            cnt--;
            answer -= fast_pow(p, k[i]);
            if(answer < 0)
                answer += k_Mod;
        }
        pr = k[i];
    }

    cout << answer << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve_test();
}