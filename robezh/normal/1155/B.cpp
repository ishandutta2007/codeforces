#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int cnt = 0;

int main() {
    cin >> n;
    cin >> str;
    for(int i = 0; i < n - 10; i++) {
        if(str[i] == '8') cnt++;
    }
    if(cnt * 2 >= n - 10) cout << "YES" << endl;
    else cout << "NO" << endl;
}