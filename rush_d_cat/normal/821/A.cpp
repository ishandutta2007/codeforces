#include <iostream>
using namespace std;
int n;
int a[52][52];
bool chk(int i, int j) {
    int ok = 0;
    if(a[i][j] == 1) return 1;
    for(int row=1;row<=n;row++) {
        for(int col=1;col<=n;col++) {
            if(row==i || col==j) {
                continue;
            }
            if(a[row][j] + a[i][col] == a[i][j]) {
                ok = 1;
            }
        }   
    }
    return ok;
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    int can = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(!chk(i, j)) can = 0;
        }
    }
    printf("%s\n", can?"Yes":"No");
}