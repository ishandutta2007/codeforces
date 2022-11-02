#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
typedef long long ll;
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }

char tmp[200005];

void f(std::string &s) {
    int len = sz(s);
    while (len % 2 == 0) len /= 2;
    while (len < sz(s)) {
        for (int i = 0; i*len < sz(s); i += 2) {
            bool greater = false;
            for (int j = 0; j < len; j++) {
                if (s[i*len + j] > s[(i+1)*len + j]) { greater = true; break; }
                else if (s[(i+1)*len + j] > s[i*len + j]) { greater = false; break; }
            }
            if (greater) {
                for (int j = 0; j < len; j++) tmp[j] = s[i*len + j];
                for (int j = 0; j < len; j++) s[i*len + j] = s[(i+1)*len + j];
                for (int j = 0; j < len; j++) s[(i+1)*len + j] = tmp[j];
            }
        }
        len *= 2;
    }
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;
    f(s); f(t);
    //std::cout << s << '\n' << t << '\n';
    std::cout << (s == t ? "YES" : "NO") << std::endl;
}