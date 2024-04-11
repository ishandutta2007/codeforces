#include <bits/stdc++.h>

using namespace std;

const long long k_Inf = 1e9;

bool check(int m, int k, int n){
    long long t = (long long)m * k;
    long long C = 1;

    long long answer = 0;

    for(int i = 0; i <= k && answer < n; ++i){
        if(i && C < k_Inf)
            C = C * (k - i + 1) / i;

        long long x = C;
        if(i)
            x = min(x, t / i);

        if(!x)
            break;

        answer += x;
        t -= x * i;
    }

    return answer >= n;
}

void solve_test(){
    int n, m;
    cin >> n >> m;

    int l = 0, r = n;
    while(l != r){
        int mid = (l + r) >> 1;
        if(check(m, mid, n))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve_test();
}