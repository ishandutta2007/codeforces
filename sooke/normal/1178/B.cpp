#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, pre[N], suf[N];
long long ans;  
std::string str;

int main() {
    std::cin >> str;
    n = str.size();
    str = " " + str + "  ";
    for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] + (str[i] == 'v' && str[i - 1] == 'v'); }
    for (int i = n; i >= 1; i--) { suf[i] = suf[i + 1] + (str[i] == 'v' && str[i + 1] == 'v'); }
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'o') { ans += 1ll * pre[i - 1] * suf[i + 1]; }
    }
    std::cout << ans << std::endl;
    return 0;
}