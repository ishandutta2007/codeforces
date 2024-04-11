#include <iostream>
using namespace std;
int v[60]=
{
31,28,31,30,31,30,31,31,30,31,30,31
, 31,28,31,30,31,30,31,31,30,31,30,31
, 31,29,31,30,31,30,31,31,30,31,30,31
, 31,28,31,30,31,30,31,31,30,31,30,31
, 31,28,31,30,31,30,31,31,30,31,30,31
};
int n;
int x[25];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> x[i];

    bool ans = 0;

    for (int i = 0; i+n-1 < 60; i ++) {
        bool fg = 1;
        for (int j = 0; j < n; j ++) {
            if (x[j] != v[i+j]) fg = 0;
        }
        ans |= fg;
    }
    printf("%s\n", ans ? "Yes" : "No");
}