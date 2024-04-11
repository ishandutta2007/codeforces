#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

int x, y;

int main() {
    int sg;
    sg = query(0, 0);

    for(int i = 29; i >= 0; i--) {
        int bit = (1 << i);
        if(sg == 0) {
            int q = query(x | bit, y);
            if(q == -1) x |= bit, y |= bit;
        }
        else {
            int q = query(x | bit, y | bit);
            if(q != sg) {
                if(sg == 1) x |= bit;
                else y |= bit;
                sg = query(x, y);
                continue;
            }

            if(sg == 1) {
                q = query(x | bit, y);
                if(q != sg) x |= bit, y |= bit;
            }
            else {
                q = query(x, y | bit);
                if(q != sg) x |= bit, y |= bit;
            }
        }
    }
    printf("! %d %d\n", x, y);
    fflush(stdout);
}