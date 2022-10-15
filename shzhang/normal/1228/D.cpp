#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, m;

int ans[100005];
vector<int> graph[100005];
int edges[300005][2];

int main()
{
    int A, B;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (i == 1) A = x, B = y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        edges[i][0] = x;
        edges[i][1] = y;
    }
    if (m == 0) {printf("-1"); return 0;}
    ans[A] = 1;
    ans[B] = 2;
    for (int i = 1; i <= n; i++) {
        if (i == A || i == B) continue;
        bool hasA = false; bool hasB = false;
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == A) hasA = true;
            if (graph[i][j] == B) hasB = true;
        }
        if (hasA && hasB) {
            ans[i] = 3;
        } else if (hasA) {
            ans[i] = 2;
        } else if (hasB) {
            ans[i] = 1;
        } else {
            printf("-1"); return 0;
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    long long cnt1, cnt2, cnt3, cnt12, cnt23, cnt13;
    cnt1 = cnt2 = cnt3 = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1)
            cnt1++;
        else if (ans[i] == 2)
            cnt2++;
        else
            cnt3++;
    }
    if (cnt1 == 0 || cnt2 == 0 || cnt3 == 0) {
        printf("-1"); return 0;
    }
    cnt12 = cnt1 * cnt2;
    cnt13 = cnt1 * cnt3;
    cnt23 = cnt2 * cnt3;
    for (int i = 1; i <= m; i++) {
        int edgevals[2];
        edgevals[0] = ans[edges[i][0]];
        edgevals[1] = ans[edges[i][1]];
        if (edgevals[0] == edgevals[1]) {
            printf("-1"); return 0;
        }
        if (edgevals[0] > edgevals[1]) {
            int t = edgevals[0];
            edgevals[0] = edgevals[1];
            edgevals[1] = t;
        }
        if (edgevals[0] == 1 && edgevals[1] == 2) {
            cnt12--;
        } else if (edgevals[0] == 1 && edgevals[1] == 3) {
            cnt13--;
        } else {
            cnt23--;
        }
    }
    if (cnt12 || cnt13 || cnt23) {
        printf("-1"); return 0;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}