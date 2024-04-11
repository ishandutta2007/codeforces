#include <bits/stdc++.h>
using namespace std;

int n;
int qx, qy;
int sx, sy, tx, ty;

int get_dimen(int x, int y){
    if(x < qx && y < qy) return 1;
    else if(x < qx && y > qy) return 2;
    else if(x > qx && y < qy) return 3;
    else return 4;
}

int main() {
    cin >> n;
    cin >> qx >> qy;
    cin >> sx >> sy >> tx >> ty;
    if(get_dimen(sx, sy) == get_dimen(tx, ty)) printf("YES");
    else printf("NO");
}