#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int a[705];
bool leftchild[705][705];
bool rightchild[705][705];
int n;

int gcdval[705][705];

int Gcd(int A, int b)
{
    if (b == 0) return A;
    return Gcd(b, A % b);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            gcdval[i][j] = Gcd(a[i], a[j]);
        }
    }
    for (int i = 1; i < n; i++) {
        if (gcdval[i][i+1] > 1) leftchild[i][i] = true;
    }
    for (int i = 2; i <= n; i++) {
        if (gcdval[i][i-1] > 1) rightchild[i][i] = true;
    }
    for (int i = 1; i <= n + 2; i++) {
        for (int j = 0; j < i; j++) leftchild[i][j] = rightchild[i][j] = true;
    }
    for (int siz = 2; siz < n; siz++) {
        for (int i = 1; i + siz - 1 <= n; i++) {
            int l = i; int r = i + siz - 1;
            //bool can_leftchild = false;
            //bool can_rightchild = false;
            if (r < n) {
                for (int j = l; j <= r; j++) {
                    if (gcdval[j][r+1] > 1 && leftchild[l][j-1] && rightchild[j+1][r]) {
                        leftchild[l][r] = true; break;
                    }
                }
            }
            if (l > 1) {
                for (int j = l; j <= r; j++) {
                    if (gcdval[j][l-1] > 1 && leftchild[l][j-1] && rightchild[j+1][r]) {
                        rightchild[l][r] = true; break;
                    }
                }
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            printf("%d %d: %d %d\n", i, j, leftchild[i][j], rightchild[i][j]);
        }
    }*/
    for (int i = 1; i <= n; i++) {
        if (leftchild[1][i-1] && rightchild[i+1][n]) {
            printf("Yes"); return 0;
        }
    }
    printf("No");
    return 0;
}