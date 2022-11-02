#include <iostream>
#include <string>
#include <algorithm>

struct S {
    std::string s;
    int i;
    bool operator<(const S &o) const {
        if (s == o.s) return i < o.i;
        else return s < o.s;
    }
};

int N;
std::string t[100005];
S s[100005];
int n[100005];

int main()
{
    std::cin >> N;
    for (int i = 0; i < N; i++) std::cin >> t[i];

    for (int i = 0; i < N; i++) s[i].s = t[i];
    for (int i = 0; i < N; i++) s[i].i = i;
    
    std::sort(s, s+N);
    for (int i = 1; i < N; i++)
        if (s[i].s == s[i-1].s)
            n[s[i].i] = n[s[i-1].i]+1;

    for (int i = 0; i < N; i++) {
        if (n[i] == 0) std::cout << "OK\n";
        else std::cout << t[i] << n[i] << '\n';
    }
}