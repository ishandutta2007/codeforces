#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

char ans[100005];
bool prev_same[100005];
bool twosame[100005];
int color[100005];

void work(void)
{
    int n;
    scanf("%d", &n);
    if (n == -1) exit(0);
    if (n == 1) {
        printf("A 1 0 0\n1\n\n\n"); return;
    }
    if (n == 2) {
        printf("Q 1 1 2\n"); char a[5];
        fflush(stdout);
        scanf("%s", a);
        if (a[0] == '1') {
            printf("A 2 0 0\n1 2\n\n\n");
        } else {
            printf("A 1 1 0\n1\n2\n\n");
        }
        return;
    }
    printf("Q %d ", n / 2);
    for (int i = 1; i + 1 <= n; i += 2) {
        printf("%d %d ", i, i+1);
    }
    printf("\n"); fflush(stdout);
    scanf("%s", ans + 1);
    for (int i = 1; i <= n / 2; i++) {
        prev_same[i * 2] = ans[i] - '0';
    }

    printf("Q %d ", (n - 1) / 2);
    for (int i = 2; i + 1 <= n; i += 2) {
        printf("%d %d ", i, i+1);
    }
    printf("\n"); fflush(stdout);
    scanf("%s", ans + 1);
    for (int i = 1; i <= (n - 1) / 2; i++) {
        prev_same[i * 2 + 1] = ans[i] - '0';
    }

    vector<int> components;
    for (int i = 1; i <= n; i++) {
        if (!prev_same[i]) components.push_back(i);
    }

    if (components.size() < 3) {
        if (components.size() == 1) {
            printf("A %d 0 0\n", n);
            for (int i = 1; i <= n; i++) printf("%d ", i);
            printf("\n\n\n"); return;
        }
        printf("A %d %d 0\n", components[1] - 1, n - components[1] + 1);
        for (int i = 1; i < components[1]; i++) printf("%d ", i);
        printf("\n");
        for (int i = components[1]; i <= n; i++) printf("%d ", i);
        printf("\n\n"); return;
    }

    vector<int> query;
    for (int i = 0; i < components.size(); i++) {
        if (i % 4 >= 2) {
            query.push_back(components[i - 2]); query.push_back(components[i]);
        }
    }
    printf("Q %d ", (int)query.size() / 2);
    for (int i = 0; i < query.size(); i++) printf("%d ", query[i]);
    printf("\n"); fflush(stdout);
    scanf("%s", ans + 1);
    for (int i = 1; i <= (int)query.size() / 2; i++) {
        twosame[query[i * 2 - 1]] = ans[i] - '0';
    }

    query.clear();
    if (components.size() > 4) {
        for (int i = 3; i < components.size(); i++) {
            if (i % 4 < 2) {
                query.push_back(components[i - 2]); query.push_back(components[i]);
            }
        }
        printf("Q %d ", (int)query.size() / 2);
        for (int i = 0; i < query.size(); i++) printf("%d ", query[i]);
        printf("\n"); fflush(stdout);
        scanf("%s", ans + 1);
        for (int i = 1; i <= (int)query.size() / 2; i++) {
            twosame[query[i * 2 - 1]] = ans[i] - '0';
        }
    }
    color[components[0]] = 1;
    color[components[1]] = 2;
    for (int i = 2; i < components.size(); i++) {
        if (twosame[components[i]]) {
            color[components[i]] = color[components[i-2]];
        } else {
            for (int c = 1; c <= 3; c++) {
                if (c != color[components[i-1]] && c != color[components[i-2]]) {
                    color[components[i]] = c; break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (prev_same[i]) color[i] = color[i-1];
    }
    vector<int> output[4];
    for (int i = 1; i <= n; i++) output[color[i]].push_back(i);
    printf("A %d %d %d\n", (int)output[1].size(), (int)output[2].size(), (int)output[3].size());
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < output[i].size(); j++) {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work(); fflush(stdout);
    }
    return 0;
}