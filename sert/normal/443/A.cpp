#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

char ch;
set <char> s;

int main() {
    //freopen("a.in", "r", stdin);
    s.insert(',');
    while (scanf("%c ", &ch) != -1)
        s.insert(ch);
    cout << s.size() - 3;
    return 0;
}