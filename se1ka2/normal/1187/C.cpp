#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, m;
    cin >> n >> m;
    int t[1002], l[1002], r[1002];
    vector<P> v;
    for(int i = 0; i < m; i++){
        cin >> t[i] >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        if(t[i] == 0) continue;
        v.push_back(P(l[i], r[i]));
    }
    sort(v.begin(), v.end());
    v.push_back(P(10000, 10000));
    int now = 1000000;
    int ans[1002];
    int p = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        if(p < i && i <= v[j].first) now--;
        while(i == v[j].first){
            p = max(p, v[j].second);
            j++;
        }
        ans[i] = now;
    }
    for(int i = 0; i < m; i++){
        if(t[i] == 0 && ans[l[i]] == ans[r[i]]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}