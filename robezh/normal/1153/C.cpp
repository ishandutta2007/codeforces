#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;
    if(n % 2 == 1) return !printf(":(");
    int lcnt = 0, rcnt = 0;
    for(char c : str) {
        if(c == '(') lcnt++;
        if(c == ')') rcnt++;
    }
    if(lcnt > n / 2 || rcnt > n / 2) return !printf(":(");
    lcnt = n / 2 - lcnt;
    rcnt = n / 2 - rcnt;
    int cur = 0;
    while(lcnt > 0) {
        if(str[cur] == '?') {
            str[cur] = '(';
            lcnt--;
        }
        cur++;
    }
    for(char &c : str) if(c == '?') c = ')';

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        char c = str[i];
        if(c == '(') cnt++;
        else cnt--;
        if(cnt < 0 || (cnt == 0 && i != n-1)) return !printf(":(");
    }
    cout << str << endl;
}