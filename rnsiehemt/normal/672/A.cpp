#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

std::string s;

void append(int i) {
    std::string t;
    while (i) {
        t += '0' + (i%10);
        i /= 10;
    }
    std::reverse(t.begin(), t.end());
    s += t;
}

int main() {
    for (int i = 1; i < 1000; i++) append(i);
    int n; scanf("%d", &n);
    printf("%d\n", s[n-1] - '0');

}