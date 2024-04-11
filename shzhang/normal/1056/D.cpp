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

int n;
vector<int> tree[100005];
int lwt[100005];
int lwt_most[100005];
int ans[100005];

void dfs(int node)
{
    if (tree[node].size() == 0) lwt[node] = 1;
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        dfs(child);
        lwt[node] += lwt[child];
    }
    lwt_most[lwt[node]]++;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        tree[p].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= 100000; i++) {
        lwt_most[i+1] += lwt_most[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1; int r = n;
        while (l < r) {
            //printf("%d %d\n", l, r);
            int mid = (l + r) / 2;
            if (lwt_most[mid] >= i) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d ", l);
    }
    return 0;
}