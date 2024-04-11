#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

char str[N];

int main() {
    cin >> str;
    int res = 0;

    for (int i = 0 ; str[i] ; ++ i) {
        char c = str[i];
        int a1 = ('@' < c);
        int a2 = ('[' > c);
        int a3 = ('`' < c);
        int a4 = ('{' > c);

        int b1 = a1 && a2;
        int b2 = a3 && a4;

        //printf("%c : %d %d - " , c , b1 , b2);

        int ch = isupper(c) ? c - 'A' + 1 : c - 'a' + 1;

        int c1 = b1 * ch;
        int c2 = b2 * ch;

        res += c1 - c2;
        //printf("%d\n" , c1 - c2);
    }
    cout << res << endl;

    return 0;
}