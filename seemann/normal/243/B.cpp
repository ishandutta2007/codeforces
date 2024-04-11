#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
const int MAXN = 1e5 + 10;

vector<int> e[MAXN];
int st[MAXN];
int x[MAXN];
int y[MAXN];
int main()
{
    //freopen("out", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
    int n, m, h, t;
    cin >> n >> m >> h >> t;
    FOR(i, m ) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        x[i] = a;
        y[i] = b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    FOR(i, n) {
        sort(e[i].begin(), e[i].end());
        st[i] = e[i].size();
    }
    FOR(i, m){
        if (st[x[i]] >= h + 1 && st[y[i]] >= t + 1 || st[x[i]] >= t + 1 && st[y[i]] >= h + 1) {
            int a = x[i];
            int b = y[i];
            if (st[a] >= t + 1 && st[b] >= h + 1)
                swap(a, b);
            int p1 = 0;
            int p2 = 0;
            int sum = 0;
            while (p1 < st[a] && p2 < st[b]){
                if (e[a][p1] == e[b][p2]) {
                    sum++;
                    p1++, p2++;
                } else {
                    if (e[a][p1] < e[b][p2]) {
                        sum++;
                        p1++;
                    } else {
                        sum++;
                        p2++;
                    }
                }
                if (sum >= h + t + 2)
                    break;
            }
            if (p1 == st[a]) {
                sum += st[b] - p2;
            }
            if (p2 == st[b]) {
                sum += st[a] - p1;
            }

            if (sum < h + t + 2)
                continue;
            vector<int> head;
            vector<int> tail;
            vector<int> both;
            p1 = 0;
            p2 = 0;
            while (p1 < st[a] && p2 < st[b]){
                if (e[a][p1] == b) {
                    p1++;
                    continue;
                }
                if (e[b][p2] == a) {
                    p2++;
                    continue;
                }
                if (e[a][p1] == e[b][p2]) {
                    both.push_back(e[a][p1]);
                    p1++, p2++;
                } else {
                    if (e[a][p1] < e[b][p2]) {
                        head.push_back(e[a][p1]);
                        p1++;
                    } else {
                        tail.push_back(e[b][p2]);
                        p2++;
                    }
                }
            }
            while (p1 < st[a]) {
                if (e[a][p1] == b)
                    continue;
                head.push_back(e[a][p1]);
                p1++;
            }
            while (p2 < st[b]) {
                if (e[b][p2] == a)
                    continue;
                tail.push_back(e[b][p2]);
                p2++;
            }
            int p = 0;
            while (head.size() < h) {
                head.push_back(both[p++]);
            }
            while (tail.size() < t) {
                tail.push_back(both[p++]);
            }
            printf("YES\n");
            printf("%d %d\n", a + 1, b + 1);
            FOR(j, h) {
                printf("%d ", head[j] + 1);
            }
            printf("\n");
            FOR(j, t) {
                printf("%d ", tail[j] + 1);
            }
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");

    return 0;
}