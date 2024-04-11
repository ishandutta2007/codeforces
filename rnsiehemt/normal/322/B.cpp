#include <cstdio>
#include <algorithm>

const int inf = 2000000001;

int a, b, c;

int f(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return -inf;
    else return x/3 + y/3 + z/3;
}

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", std::max(std::max(f(a, b, c), f(a-1, b-1, c-1)+1), f(a-2, b-2, c-2)+2));
}