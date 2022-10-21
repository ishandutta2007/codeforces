#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n;
string qs[3];
string str;
string fs[3];
int mp[N];

string ask(string str) {
    cout << "? " + str << endl;
    fflush(stdout);
    string res; cin >> res; return res;
}

int main() {
    cin >> str;
    n = str.length();
    for(int i = 0; i < n; i++) {
        int x = i;
        for(int j = 0; j < 3; j++) {
            qs[j].push_back((char)(x % 26 + 'a'));
            x /= 26;
        }
    }
    for(int i = 0; i < 3; i++) fs[i] = ask(qs[i]);
    for(int i = 0; i < n; i++) {
        int res = 0;
        for(int j = 2; j >= 0; j--) {
            res *= 26;
            res += (fs[j][i] - 'a');
        }
        mp[res] = i;
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << str[mp[i]];
    cout << endl;
    fflush(stdout);

}