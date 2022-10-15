#include <cstdio>

using namespace std;


int main()
{
    int a;
    scanf("%d", &a);
    //int cnt = 0;
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            printf("%d%d", i, a/i);
            break;
        }
    }
    return 0;
}