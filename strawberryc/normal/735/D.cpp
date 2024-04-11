#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

int n;

bool prime(int n)
{
    int i, S = sqrt(n);
    For (i, 2, S) if (n % i == 0) return 0;
    return 1;
}

int main()
{
    std::cin >> n;
    if (n == 1 || n == 2 || prime(n)) puts("1");
    else if ((n & 1) && !prime(n - 2)) puts("3");
    else puts("2");
    return 0;
}