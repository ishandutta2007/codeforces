#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N;
char s[MaxN];
std::vector<std::string> a, b;

int main()
{
    scanf(" %s", s);
    N = strlen(s);
    std::string t;
    bool num = false, zerolead = false;
    for (int i = 0; i < N; i++) {
        if (s[i] == ',' || s[i] == ';') {
            if (num) a.push_back(t);
            else b.push_back(t);
            t = "";
            num = false;
            zerolead = false;
        } else {
            if (t.empty()) {
                num = true;
                if (s[i] == '0') zerolead = true;
            } else if (zerolead) num = false;
            if (s[i] < '0' || s[i] > '9') num = false;
            t += s[i];
        }
    }
    if (num) a.push_back(t);
    else b.push_back(t);

    if (a.empty()) printf("-\n");
    else {
        printf("\"");
        for (int i = 0; i < sz(a); i++) {
            printf("%s", a[i].c_str());
            if (i < sz(a)-1) printf(",");
        }
        printf("\"\n");
    }
    if (b.empty()) printf("-\n");
    else {
        printf("\"");
        for (int i = 0; i < sz(b); i++) {
            printf("%s", b[i].c_str());
            if (i < sz(b)-1) printf(",");
        }
        printf("\"\n");
    }
}