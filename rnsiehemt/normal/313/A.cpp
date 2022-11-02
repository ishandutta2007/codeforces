#include <cstdio>
#include <algorithm>

int N;

int main()
{
    scanf("%d", &N);
    if (N > 0) printf("%d\n", N);
    else printf("%d\n", -std::min((-N)/10, ((-N)/100)*10+(-N)%10));
}