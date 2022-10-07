#include <cstdio>
#include <iostream>

using namespace std;

int ar[3][3];

int main() {
    int s = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> ar[i][j];
            s += ar[i][j];
        }
    }
    int sumneed = s / 2;
    for(int i = 0; i < 3; ++i) {
        int s = 0;
        for(int j=  0; j < 3; ++j) {
            s += ar[i][j];
        }
        int need = sumneed - s;
        ar[i][i] = need;
    }
    for(int i = 0; i < 3; ++i) {
        string sep;
        for(int j = 0; j < 3; ++j) {
            cout << sep;
            cout << ar[i][j];
            sep = " ";
        }
        cout << endl;
    }
}