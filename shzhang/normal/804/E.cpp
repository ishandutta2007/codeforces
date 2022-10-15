#include <cstdio>

using namespace std;

int s4[] = {1, 2, 1, 3, 2, 4, 1, 4, 2, 3, 3, 4};
int s5[] = {1, 2, 1, 3, 1, 4, 2, 3, 2, 5, 3, 5, 1, 5, 3, 4, 2, 4, 4, 5};
int s44[] = {1, 5, 1, 6, 1, 7, 2, 5, 2, 8, 1, 8, 2, 7, 3, 5, 4, 6, 3, 6,
    2, 6, 3, 7, 4, 5, 4, 8, 3, 8, 4, 7};
int s45[] = {2, 6, 1, 8, 2, 9, 4, 5, 3, 7, 3, 8, 1, 9, 4, 6, 2, 5, 1, 7,
    4, 7, 3, 5, 4, 9, 3, 9, 2, 8, 1, 6, 3, 6, 4, 8, 2, 7, 1, 5};

int n;

void execute(int* arr, int opcnt, int off)
{
    for (int i = 0; i < opcnt * 2; i += 2) {
        printf("%d %d\n", arr[i] + off - 1, arr[i+1] + off - 1);
    }
}

void execute2(int* arr, int opcnt, int off1, int off2)
{
    for (int i = 0; i < opcnt * 2; i += 2) {
        printf("%d %d\n", arr[i] + off1 - 1, arr[i+1] + off2 - 5);
    }
}

int main()
{
    scanf("%d", &n);
    if (n % 4 > 1) {
        printf("NO"); return 0;
    }
    printf("YES\n");
    if (n == 1) return 0;
    if (n % 4 == 0) {
        for (int i = 1; i <= n; i += 4) {
            execute(s4, 6, i);
        }
        for (int i = 1; i <= n; i += 4) {
            for (int j = i + 4; j <= n; j += 4) {
                execute2(s44, 16, i, j);
            }
        }
    } else {
        for (int i = 1; i < n - 4; i += 4) {
            execute(s4, 6, i);
        }
        execute(s5, 10, n - 4);
        for (int i = 1; i < n; i += 4) {
            for (int j = i + 4; j < n; j += 4) {
                if (j == n - 4) {
                    execute2(s45, 20, i, j);
                } else {
                    execute2(s44, 16, i, j);
                }
            }
        }
    }
    return 0;
}