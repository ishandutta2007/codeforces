#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int b = 1 << 17, s = (1 << 18) - 1;

int a[3][3];

int main()
{
    int k;
    cin >> k;
    if(!k) {
        puts("1 1");
        puts("1");
    }
    else {
        puts("3 3");
        a[0][0] = b | k;
        a[0][1] = k;
        a[1][0] = b;
        a[1][1] = s;
        a[1][2] = k;
        a[2][2] = s;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                printf("%d ", a[i][j]);
            }
            puts("");
        }
    }
}