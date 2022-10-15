#include <cstdio>

using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    if (x % 4 == 0) {
        printf("1 A");
    } else if (x % 4 == 1) {
        printf("0 A");
    } else if (x % 4 == 2) {
        printf("1 B");
    } else {
        printf("2 A");
    }
    return 0;
}