#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

vector<int> v[200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) v[i].clear();
        int c[200005];
        for(int i = 0; i < n; i++){
            cin >> c[i];
            c[i]--;
            v[c[i]].push_back(i);
        }
        int s = 0;
        for(int i = 0; i < n; i++) s += min((int)v[i].size(), k);
        s = s / k * k;
        P p[200005];
        for(int i = 0; i < n; i++) p[i] = P((int)v[i].size(), i);
        sort(p, p + n, greater<P>());
        int ans[200005];
        for(int i = 0; i < n; i++) ans[i] = -1;
        int j = 0, l = 0;
        for(int i = 0; i < s; i++){
            if(l == min(p[j].first, k)){
                j++;
                l = 0;
            }
            ans[v[p[j].second].back()] = i % k;
            v[p[j].second].pop_back();
            l++;
        }
        for(int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
        cout << endl;
    }
}