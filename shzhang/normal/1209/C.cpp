#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

char s[200005];
int color[200005];

int main()
{
    int t;
    scanf("%d", &t);
    for (int data = 1; data <= t; data++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) color[i] = 0;
        scanf("%s", s + 1);
        bool found_sol = false;
        for (int bound = 0; bound <= 10; bound++) {
            for (int i = 1; i <= n; i++) {
                if (s[i] - '0' < bound) color[i] = 1;
            }
            for (int i = n; i >= 1; i--) {
                if (color[i] == 1) break;
                if (s[i] - '0' == bound) color[i] = 1;
            }
            vector<int> ansseq;
            for (int i = 1; i <= n; i++) {
                if (color[i] == 1) ansseq.push_back(s[i] - '0');
            }
            for (int i = 1; i <= n; i++) {
                if (color[i] != 1) ansseq.push_back(s[i] - '0');
            }
            bool fail = false;
            for (int i = 0; i < n - 1; i++) {
                if (ansseq[i] > ansseq[i+1]) {
                    fail = true; break;
                }
            }
            if (!fail) {
                for (int i = 1; i <= n; i++) {
                    printf("%d", color[i] == 1 ? 1 : 2);
                }
                printf("\n");
                found_sol = true; break;
            }
        }
        if (!found_sol) printf("-\n");
    }
    return 0;
}