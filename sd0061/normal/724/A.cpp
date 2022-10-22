#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int check(string str) {
    if (str[0] == 'm') {
        return 1;
    }
    if (str[0] == 't' && str[1] == 'u') {
        return 2;
    }
    if (str[0] == 'w') {
        return 3;
    }
    if (str[0] == 't' && str[1] == 'h') {
        return 4;
    }
    if (str[0] == 'f') {
        return 5;
    }
    if (str[0] == 's' && str[1] == 'a') {
        return 6;
    }
    if (str[0] == 's') {
        return 7;
    }
}

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    string A , B;
    cin >> A >> B;
    int w = (check(B) - check(A) + 7) % 7;
    for (int i = 0 ; i < 12 ; ++ i) {
        if (month[i] % 7 == w) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}