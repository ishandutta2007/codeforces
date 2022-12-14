#include <bits/stdc++.h>
using namespace std;
#define N 400005
typedef pair<int,int> pp;
string a[N];
long long b[N];
int n;
int where[N];

int BIT1[N], BIT2[N];
void update(int i, int val) {
    while(i < N) {
        BIT1[i] += val;
        if (val < 0) BIT2[i]--;
        else BIT2[i]++;
        i += i & (-i);
    }
}

int query(int how) {
    int idx = 0;
    for(int i=20; i>=0; i--) {
        if (idx + (1 << i) >= N) continue;
        int now = idx + (1 << i);

        if (BIT2[now] <= how) {
            idx += (1 << i); how -= BIT2[now];
        }
    }

    int ret = 0;
    while(idx) {
        ret += BIT1[idx];
        idx -= (idx & (-idx));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];

    int ans = 0, how = 0;
    for(int i=0; i<n; i++) {
        if (a[i] == "11") ans += b[i], how++;
    }

    vector<pp> zeroone, onezero, total;
    for(int i=0; i<n; i++) if (a[i] == "01") zeroone.push_back(make_pair(b[i], i));
    for(int i=0; i<n; i++) if (a[i] == "10") onezero.push_back(make_pair(b[i], i));
    for(int i=0; i<n; i++) if (a[i] != "11") total.push_back(make_pair(b[i], i));
    sort(total.begin(), total.end(), greater<pp>());
    for(int i=0; i<total.size(); i++) {
        update(i + 1, +total[i].first);
        where[total[i].second] = i + 1;
    }
    sort(zeroone.begin(), zeroone.end());
    sort(onezero.begin(), onezero.end());

    int taken = how;
    int bestAns = ans;
    for(int tot = how; tot <= n; tot++) {
        if (taken * 2 < tot) {
            if (onezero.empty() || zeroone.empty()) break;
            pp l1 = *onezero.rbegin(); ans += l1.first;
            pp l2 = *zeroone.rbegin(); ans += l2.first;
            onezero.pop_back(), zeroone.pop_back();
            update(where[l1.second], -l1.first);
            update(where[l2.second], -l2.first);

            taken++;
        }

        int have = taken * 2 - how;
        if (tot < have) continue;
        int need = tot - have;
        bestAns = max(bestAns, ans + query(need));
       // cout << bestAns << endl;
    }

    cout << bestAns << endl;






    return 0;

}