#include <iostream>
#include <string>
using namespace std;

int main() {
    string t;
    cin >> t;
    int n = t.size();
    char c[26 * 26 * 26];
    string r[3];
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26 * 26; j++) c[i * 26 * 26 + j] = 'a' + i;
    }
    cout << "? ";
    for(int i = 0; i < n; i++) cout << c[i];
    cout << endl;
    fflush(stdout);
    cin >> r[0];
    for(int i = 0; i < 26 * 26; i++){
        for(int j = 0; j < 26; j++) c[i * 26 + j] = 'a' + (i % 26);
    }
    cout << "? ";
    for(int i = 0; i < n; i++) cout << c[i];
    cout << endl;
    fflush(stdout);
    cin >> r[1];
    for(int i = 0; i < 26 * 26 * 26; i++) c[i] = 'a' + (i % 26);
    cout << "? ";
    for(int i = 0; i < n; i++) cout << c[i];
    cout << endl;
    fflush(stdout);
    cin >> r[2];
    int ans[10002];
    for(int i = 0; i < n; i++){
        int p = 0;
        p += 26 * 26 * (r[0][i] - 'a');
        p += 26 * (r[1][i] - 'a');
        p += (r[2][i] - 'a');
        ans[p] = i;
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << t[ans[i]];
}