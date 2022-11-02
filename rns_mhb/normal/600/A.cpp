#include <bits/stdc++.h>
using namespace std;

#define N 100005

char s[N];
vector<string> num, other;
string now;

bool isnum(string s) {
    if (s.empty()) return 0;
    if (s.size() > 1 && s[0] == '0') return 0;
    for (int i = 0; i < s.size(); i ++) if (s[i] < '0' || s[i] > '9') return 0;
    return 1;
}

void print(vector<string> &vs) {
    if (vs.empty()) puts("-");
    else {
        putchar('"');
        for (int i = 0; i < vs.size(); i ++) {
            printf("%s", vs[i].c_str());
            if (i != vs.size() - 1) putchar(',');
        }
        putchar('"');
        puts("");
    }
}

int n;

int main() {
    gets(s);
    n = strlen(s);
    s[n] = ',';
    for (int i = 0; i <= n; i ++) {
        if (s[i] == ',' || s[i] == ';') {
            if (isnum(now)) num.push_back(now);
            else other.push_back(now);
            now.clear();
        }
        else now += s[i];
    }
    print(num);
    print(other);
    return 0;
}