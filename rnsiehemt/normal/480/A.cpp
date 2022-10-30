#include <cstdio>
#include <algorithm>
#include <utility>

int N;
std::pair<int, int> a[5005];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    
    std::sort(a, a+N);

    int c = a[0].second;
    for (int i = 1; i < N; i++) {
        if (a[i].second >= c) c = a[i].second;
        else c = a[i].first;
    }

    printf("%d\n", c);
}