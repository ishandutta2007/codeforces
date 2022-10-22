#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int cnt = 0;
    while (i != n && s[i] == '<') {
        cnt++;
        i++;
    }
    i = n - 1;
    while (i != -1 && s[i] == '>') {
        cnt++;
        i--;
    }
    cout << cnt;
}