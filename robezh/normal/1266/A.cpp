#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
string str;

bool check(string s) {
    int have_zero = 0, sum = 0;
    int even_cnt = 0;
    for(char c : str) {
        if(c == '0') have_zero = 1;
        if((c - '0') % 2 == 0) {
            even_cnt++;
        }
        sum = (sum + (c - '0'))% 3;
    }
    return have_zero && even_cnt >= 2 && sum == 0;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> str;
        if(check(str)) cout << "red" << '\n';
        else cout << "cyan" << "\n";
    }
}