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

int freqleft[200005];
int freqright[200005];
int bothcnt;
int a[200005];

int n, q;

int maxfreq(int l, int r)
{
    vector<int> elem;
    for (int i = l; i <= r; i++) elem.push_back(a[i]);
    sort(elem.begin(), elem.end());
    int freq = 1;
    int maxfreq = 1;
    for (int i = 1; i < elem.size(); i++) {
        if (elem[i] != elem[i-1]) {
            freq = 1;
        } else {
            freq++;
        }
        maxfreq = max(maxfreq, freq);
    }
    return maxfreq;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) freqright[a[i]]++;
    vector<int> cuts;
    for (int i = 1; i <= n; i++) {
        int old_bothcnt = (freqleft[a[i]] && freqright[a[i]] ? 1 : 0);
        freqleft[a[i]]++; freqright[a[i]]--;
        int new_bothcnt = (freqleft[a[i]] && freqright[a[i]] ? 1 : 0);
        bothcnt -= old_bothcnt - new_bothcnt;
        if (bothcnt == 0) cuts.push_back(i);
    }
    int prev = 1;
    int ans = 0;
    for (int i = 0; i < cuts.size(); i++) {
        ans += cuts[i] - prev + 1 - maxfreq(prev, cuts[i]);
        prev = cuts[i] + 1;
    }
    printf("%d", ans);
    return 0;
}