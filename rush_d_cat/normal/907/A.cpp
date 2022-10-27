#include <iostream>
using namespace std;
int v1, v2, v3, vm;
int main() {
    cin >> v1 >> v2 >> v3 >> vm;
    for (int i = 1; i <= 200; i ++) {
        for (int j = 1; j <= 200; j ++) {
            for (int k = 1; k <= 200; k ++) {
                if (i > j && j > k) {
                    if ( (i>=v1 && i<=2*v1) && (j>=v2 && j<=2*v2) && (k>=v3 && k<=2*v3)
                    && (k>=vm && k<=2*vm) && (i>2*vm && j>2*vm) )
                    {
                        printf("%d\n%d\n%d\n", i,j,k);
                        return 0;
                    }
                }
            }
        }
    }

    printf("-1\n");
}