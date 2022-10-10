#include <bits/stdc++.h>
using namespace std;

map<int, int> num;
int n;
const int MAXN = 2e5 + 2;
const int MAXL = 19;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        num[s]++;
    }
    vector<long long> cts;
    for(auto p : num)
    {
        cts.push_back(p.second);
    }
    sort(cts.begin(), cts.end());
    vector<int> cnd;
    int m = cts.size();
    long long ans = 0;
    for(int l = 1; l < MAXL; l++)
    {
        for(int i = 0; i + l - 1 < m; i++)
        {
            long long mult = 1;
            long long x = 1000000000;
            for(int j = i; j < i + l; j++)
            {
                x = min(x, cts[j]/mult);
                mult *= 2;
            }
            /*for(auto c : cnd)
                cout << c << " ";
            cout << endl;*/
            long long att = 0;
            mult = 1;
            for(int j = 0; j < l; j++)
            {
                att += mult*x;
                mult *= 2;
            }
            ans = max(ans, att);
        }
    }
    cout << ans << endl;
}