#include <iostream>
using namespace std;

int x, y;
int main() {
    cin >> x >> y;
    if (y == 0) {
        printf("No\n"); 
        return 0;
    }
    if (x == 0 && y == 1) {
        printf("Yes\n");
        return 0;
    }
    if (x > 0 && y == 1) {
        printf("No\n");
        return 0;
    }
    int cur = y - 1;
    if ( (x - cur >= 0) && ((x-cur)%2 == 0) ) printf("Yes\n");
    else printf("No\n");
}