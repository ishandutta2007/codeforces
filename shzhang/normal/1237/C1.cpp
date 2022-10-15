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

int n;

int x[50005];
int y[50005];
int z[50005];
int seq[50005];

bool cmp(int a, int b)
{
    if (x[a] != x[b]) {
        return x[a] < x[b];
    } else if (y[a] != y[b]) {
        return y[a] < y[b];
    } else {
        return z[a] < z[b];
    }
}

vector<int> planes[50005];
bool gone[50005];


int absolute(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", x + i, y + i, z + i);
        seq[i] = i;
    }
    sort(seq + 1, seq + n + 1, cmp);
    int curplane = 1;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && x[seq[i]] != x[seq[i-1]]) curplane++;
        planes[curplane].push_back(seq[i]);
    }
    for (int i = 1; i <= curplane; i++) {
        while (!planes[i].empty()) {
            while (!planes[i].empty() && gone[planes[i].back()]) {
                planes[i].pop_back();
            }
            if (planes[i].empty()) break;
            int node = planes[i].back();
            planes[i].pop_back();
            while (!planes[i].empty() && gone[planes[i].back()]) {
                planes[i].pop_back();
            }
            if (planes[i].size() == 0) {
                int bestchoice = 0;
                int bestabs = 2000000000;
                for (int j = 0; j < planes[i+1].size(); j++) {
                    int dist = absolute(y[planes[i+1][j]] - y[node]) + absolute(
                        z[planes[i+1][j]] - z[node]);
                    if (dist < bestabs) {
                        bestabs = dist; bestchoice = planes[i+1][j];
                    }
                }
                printf("%d %d\n", node, bestchoice);
                gone[node] = gone[bestchoice] = true;
            } else if (y[planes[i].back()] != y[node]){
                int prevy = y[planes[i].back()];
                int j = planes[i].size()-1;
                int bestchoice = 0;
                int bestabs = 1000000000;
                while (j >= 0 && y[planes[i][j]] == prevy) {
                    if (gone[planes[i][j]]) {j--; continue;}
                    if (absolute(z[planes[i][j]] - z[node]) < bestabs) {
                        bestabs = absolute(z[planes[i][j]] - z[node]);
                        bestchoice = planes[i][j];
                    }
                    j--;
                }
                printf("%d %d\n", node, bestchoice);
                gone[node] = gone[bestchoice] = true;
            } else {
                printf("%d %d\n", node, planes[i].back());
                gone[node] = gone[planes[i].back()] = true;
            }
        }
    }
    return 0;
}