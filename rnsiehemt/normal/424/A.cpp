#include <cstdio>
#include <algorithm>

int N;
char a[205];
int b, c;

int main()
{
    scanf("%d", &N);
    scanf(" %s", a);
    for (int i = 0; i < N; i++) {
        if (a[i] == 'X') b++;
        else c++;
    }
    printf("%d\n", std::abs(b-N/2));
    for (int i = 0; i < N; i++) {
        if (b > N/2 && a[i] == 'X') {
            a[i] = 'x'; b--;
        }
        else if (c > N/2 && a[i] == 'x') {
            a[i] = 'X'; c--;
        }
    }
    printf("%s\n", a);
}