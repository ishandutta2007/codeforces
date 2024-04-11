#include <cstdio>
#include <vector>

using namespace std;

struct Cycle {
    int a[4];
};

vector<Cycle> cycles;

void cycle(int a, int b, int c)
{
    Cycle cy; cy.a[0] = a; cy.a[1] = b; cy.a[2] = c; cy.a[3] = 0;
    cycles.push_back(cy);
}

void cycle(int a, int b, int c, int d)
{
    Cycle cy; cy.a[0] = a; cy.a[1] = b; cy.a[2] = c; cy.a[3] = d;
    cycles.push_back(cy);
}

int n;

void work(int s)
{
    for (int i = 1; i <= s; i += 2) {
        for (int j = i + 2; j <= s; j += 2) {
            if (i == s - 3 && j == s - 1) {
                cycle(s-1, s-2, s-3);
                cycle(s, s-2, s-3);
                cycle(s, s-1, s-3);
                cycle(s, s-1, s-2);
            } else if (j == i + 2) {
                cycle(i, i+1, j);
                cycle(i, i+1, j+1);
                cycle(i, j+1, i+1, j);
            } else {
                cycle(i, j, i+1, j+1);
                cycle(i, j, i+1, j+1);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    if (n == 3) {
        printf("2\n3 1 2 3\n3 1 2 3"); return 0;
    }
    if (n == 5) {
        printf("6\n3 5 4 2\n3 3 1 5\n4 4 5 2 3\n");
        printf("4 4 3 2 1\n3 4 2 1\n3 3 1 5");
        return 0;
    }
    if (n % 2 == 0) {
        work(n);
    } else {
        work(n - 3);
        for (int i = 1; i <= n - 3; i += 2) {
            cycle(i, n-2, i+1, n-1);
            cycle(i, n-1, i+1, n);
            cycle(i, n-2, i+1, n);
        }
        cycle(n-2, n-1, n);
        cycle(n-2, n-1, n);
    }
    printf("%d\n", (int)cycles.size());
    for (int i = 0; i < cycles.size(); i++) {
        Cycle cy = cycles[i];
        if (cy.a[3]) {
            printf("4 %d %d %d %d\n", cy.a[0], cy.a[1], cy.a[2], cy.a[3]);
        } else {
            printf("3 %d %d %d\n", cy.a[0], cy.a[1], cy.a[2]);
        }
    }
    return 0;
}