#include <bits/stdc++.h>
using namespace std;

string s[4];
bool in(int x , int y) {
    return 0 <= x && x < 4 && 0 <= y && y < 4;
}

int main() {
    for (int i = 0 ; i < 4 ; ++ i) {
        cin >> s[i];
    }
    for (int i = 0 ; i < 4 ; ++ i) {
        for (int j = 0 ; j < 4 ; ++ j) {
            if (s[i][j] == '.') {
                s[i][j] = 'x';

                for (int x = 0 ; x < 4 ; ++ x) {
                    for (int y = 0 ; y < 4 ; ++ y) {
                        int l = 0;
                        while (in(x , y + l) && s[x][y + l] == 'x') {
                            ++ l;
                        }
                        if (l >= 3) {
                            puts("YES");
                            return 0;
                        }

                        l = 0;
                        while (in(x + l, y) && s[x + l][y] == 'x') {
                            ++ l;
                        }
                        if (l >= 3) {
                            puts("YES");
                            return 0;
                        }

                        l = 0;
                        while (in(x + l, y + l) && s[x + l][y + l] == 'x') {
                            ++ l;
                        }
                        if (l >= 3) {
                            puts("YES");
                            return 0;
                        }

                        l = 0;
                        while (in(x + l, y - l) && s[x + l][y - l] == 'x') {
                            ++ l;
                        }
                        if (l >= 3) {
                            puts("YES");
                            return 0;
                        }


                    }
                }


                s[i][j] = '.';
            }
        }
    }
    puts("NO");
}