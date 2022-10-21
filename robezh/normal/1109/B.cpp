#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
string s;

bool is_palin(string &str) {
    int len = str.length();
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - 1 - i]) return false;
    }
    return true;

}

bool same(string &str) {
    int len = str.length();
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[0]) return false;
    }
    return true;
}

int main() {
    cin >> s;
    n = s.length();

    if(same(s)) return !printf("Impossible");
    for(int i = 1; i < n; i++) {
        string str = s.substr(i) + s.substr(0, i);
        if(str == s) continue;
        if(is_palin(str)) return !printf("1");
    }
    return !printf("2");


}