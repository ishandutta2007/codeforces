#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int l[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
std::string s[] = {
    "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"
};

std::string a, b;
int x, y;

int main() {
    std::cin >> a >> b;
    for (int i = 0; i < 7; i++) if (a == s[i]) x = i;
    for (int i = 0; i < 7; i++) if (b == s[i]) y = i;
    for (int i = 0; i+1 < 12; i++) if ((x + l[i]) % 7 == y) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
}