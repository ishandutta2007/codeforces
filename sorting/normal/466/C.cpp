#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    const int k_N = 5e5 + 7;
    static int a[k_N];
    static long long prefix[k_N], suffix[k_N];
    static int cnt_prefix[k_N], cnt_suffix[k_N];

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    for(int i = n; i >= 1; --i)
        suffix[i] = suffix[i + 1] + a[i];

    long long sum = 0;
    for(int i = 1; i <= n; ++i)
        sum += a[i];

    if(sum % 3){
        cout << "0\n";
        return 0;
    }

    long long d = sum / 3;
    for(int i = 1; i <= n; ++i)
        cnt_prefix[i] = (prefix[i] == d) + cnt_prefix[i - 1];
    for(int i = n; i >= 1; --i)
        cnt_suffix[i] = (suffix[i] == d) + cnt_suffix[i + 1];

    long long answer = 0;
    for(int i = 1; i <= n - 2; ++i){
        if(prefix[i] != d)
            continue;

        answer += cnt_suffix[i + 2];
    }

    cout << answer << "\n";
}