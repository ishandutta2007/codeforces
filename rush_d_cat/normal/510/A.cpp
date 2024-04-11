#include <iostream>
using namespace std;
char s[52][52];
int n, m;
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            s[i][j] = '#';
        }
    }
    for(int i=2;i<=n;i+=2) {
        if(i%4 == 2) {
            for(int j=1;j<m;j++) {
                s[i][j] = '.';
            }
        } else {
            for(int j=2;j<=m;j++) {
                s[i][j] = '.';
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout << s[i][j];
        }
        cout << endl;
    }
}