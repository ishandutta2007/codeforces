/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> cap(n);
    vector<int> fromMilestones(n);
    ll actualTotal = 0;
    
    auto deductContribution = [&] (int i) {
        actualTotal -= max(cap[i], fromMilestones[i]);
    };
    auto addContribution = [&] (int i) {
        actualTotal += max(cap[i], fromMilestones[i]);
    };
    
    auto modifyMilestoneCount = [&] (int i, int d) {
        deductContribution(i);
        fromMilestones[i] += d;
        addContribution(i);
    };
    
    for (int &v : cap) cin >> v;
    for (int v : cap) actualTotal += v;
    int q; cin >> q;
    map<pair<int, int>, int> milestones;
    for (int qta = 0; qta < q; ++qta) {
        int s, t, u; cin >> s >> t >> u;
        --s; --u;
        if (milestones.count(make_pair(t, s)) > 0) {
            modifyMilestoneCount(milestones[make_pair(t, s)], -1);
            milestones.erase(make_pair(t, s));
        }
        if (u >= 0) {
            modifyMilestoneCount(u, 1);
            milestones[make_pair(t, s)] = u;
        }
        cout << actualTotal - milestones.size() << endl;
    }

    return 0;
}