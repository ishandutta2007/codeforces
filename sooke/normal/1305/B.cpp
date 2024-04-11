#include <bits/stdc++.h>

int n;
std::string str;
std::vector<int> ans;

int main() {
    std::cin >> str;
    n = str.size();
    str = " " + str;
    int i = 1, j = n;
    while (true) {
        for (; i <= n && str[i] != '('; i++);
        for (; j >= 1 && str[j] != ')'; j--);
        if (i <= j && str[i] == '(' && str[j] == ')') {
            ans.push_back(i);
            ans.push_back(j);
            i++; j--;
        } else {
            break;
        }
    }
    if (ans.empty()) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
        std::cout << ans.size() << std::endl;
        std::sort(ans.begin(), ans.end());
        for (auto x : ans) { std::cout << x << " "; }
    }
    return 0;
}