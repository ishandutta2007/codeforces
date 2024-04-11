#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 200100;

int N;
vector <pair <int, bool> > edge[MAXN]; //true = [] to int, false is other way
int ans;
vector<int> alist;

int count(int node, int prev) {
    int t = 0;
    for (int i=0; i<edge[node].size(); ++i) {
        if (edge[node][i].first == prev) continue;
        t += (edge[node][i].second ? 0 : 1) + count(edge[node][i].first, node);
    }
    return t;
}
int s0() {
    return count(0, -1);
}

void run (int cloc, int csum, int last)
{
    //cout << cloc << " " << csum << " " << last << "\n";
    if (csum < ans)
    {
        ans = csum;
        alist.clear();
        alist.push_back (cloc);
    }
    else if (csum == ans)
        alist.push_back (cloc);
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        if (edge[cloc][i].first != last)
        {
            int nsum = csum + 1; if (!edge[cloc][i].second) nsum -= 2;
            run (edge[cloc][i].first, nsum, cloc);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b; a--, b--;
        edge[a].push_back (make_pair (b, true));
        edge[b].push_back (make_pair (a, false));
    }
    
    int x = s0();
    //cout << x << "\n";
    ans = x;
    run (0, x, -1);
    
    sort (alist.begin(), alist.end());
    cout << ans << "\n";
    for (int i = 0; i < alist.size(); i++)
        cout << alist[i] + 1 << " ";
    cout << "\n";
    return 0;
}