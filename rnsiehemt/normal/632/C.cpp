#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 50*1000+5;

int N;
std::string s[MaxN];

bool c(const std::string &a, const std::string &b) {
    return a+b < b+a;
}

int main()
{
    std::cin >> N;
    for (int i = 0; i < N; i++) std::cin >> s[i];
    std::sort(s, s+N, c);
    for (int i = 0; i < N; i++) std::cout << s[i];
    std::cout << '\n';
}