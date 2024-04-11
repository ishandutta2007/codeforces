
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int main()
{
    int val;
    char a[50], b[50];
    scanf("%d%s%s", &val, a, b);
    if (b[0] == 'w') {
        if (val == 5 || val == 6) {
            printf("53");
        } else {
            printf("52");
        }
    } else {
        if (val <= 29) {
            printf("12");
        } else if (val == 30) {
            printf("11");
        } else if (val == 31) {
            printf("7");
        }
    }
    return 0;
}