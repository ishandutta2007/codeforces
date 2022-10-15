#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>
#include <random>
#include <chrono>

using namespace std;

#define ll long long

int n, m;
int p[2005];
int partner[2005];
bool taken[2005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", p + i);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        partner[a] = b; partner[b] = a;
    }
    int t;
    scanf("%d", &t);
    int remaining = 2 * n;
    int nxtreq = 0;
    while (remaining) {
        if (t == 1) {
            int choice;
            if (nxtreq) {
                choice = nxtreq;
            } else {
                if (remaining == 1) {
                    int rem = 0;
                    for (int i = 1; i <= 2 * n; i++) {
                        if (!taken[i]) rem = i;
                    }
                    choice = rem;
                } else {
                    vector<int> pwrs;
                    for (int i = 1; i <= 2 * n; i++) {
                        if (!taken[i]) pwrs.push_back(p[i]);
                    }
                    sort(pwrs.begin(), pwrs.end());
                    int bestval = -1000000;
                    for (int i = 1; i <= 2 * n; i++) {
                        if (taken[i]) continue;
                        if (partner[i]) {
                            if (p[i] > p[partner[i]]) {
                                choice = i;
                            } else {
                                choice = partner[i];
                            }
                            break;
                        } else {
                            if (p[i] > bestval) {
                                bestval = p[i]; choice = i;
                            }
                        }
                    }
                }
            }
            printf("%d\n", choice); fflush(stdout);
            taken[choice]  = true;
            t = 2; remaining--;
        } else {
            int x; scanf("%d", &x);
            taken[x] = true;
            if (partner[x] && !taken[partner[x]])  {
                nxtreq = partner[x];
            } else {
                nxtreq = 0;
            }
            t = 1; remaining--;
        }
    }
    return 0;
}