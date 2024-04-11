#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    char c[4];
    int cnt[4] = {} , w[4] = {};
    for (int i = 0 ; i < str.size() ; ++ i) {
        if (str[i] != '!') {
            c[i % 4] = str[i];
            ++ cnt[i % 4];
        }
        ++ w[i % 4];
    }
    for (int i = 0 ; i < 4 ; ++ i) {
        if (c[i] == 'R') {
            printf("%d " , w[i] - cnt[i]);
        }
    }
    for (int i = 0 ; i < 4 ; ++ i) {
        if (c[i] == 'B') {
            printf("%d " , w[i] - cnt[i]);
        }
    }
    for (int i = 0 ; i < 4 ; ++ i) {
        if (c[i] == 'Y') {
            printf("%d " , w[i] - cnt[i]);
        }
    }
    for (int i = 0 ; i < 4 ; ++ i) {
        if (c[i] == 'G') {
            printf("%d\n" , w[i] - cnt[i]);
        }
    }

}