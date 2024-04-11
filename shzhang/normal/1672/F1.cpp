#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
int a[200005];
int freq[200005];
vector<int> pos[200005];
int ans[200005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        freq[i] = 0;
        pos[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        freq[a[i]]++;
        pos[a[i]].push_back(i);
    }
    vector<pair<int, int> > freqs;
    for (int i = 1; i <= n; i++) {
        freqs.push_back(make_pair(freq[i], i));
    }
    sort(freqs.begin(), freqs.end());
    reverse(freqs.begin(), freqs.end());
    int cycles = freqs[0].first;
    vector<int> vals;
    //debug("here");
    for (int i = 1; i <= cycles; i++) {
        vals.clear();
        for (int j = 0; (j < n && (j == 0 || freq[freqs[j].second] == freq[freqs[j-1].second])); j++) {
            vals.push_back(freqs[j].second);
        }
        for (int j = 0; j + 1 < vals.size(); j++) {
            ans[pos[vals[j]].back()] = vals[j+1];
        }
        ans[pos[vals.back()].back()] = vals[0];
        for (int j = 0; j < vals.size(); j++) {
            //printf("! %d (%d)", vals[j], pos[vals[j]].back());
            pos[vals[j]].pop_back();
            freq[vals[j]]--;
        }
        //printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}