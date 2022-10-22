#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        ll w;
        cin >> n >> w;
        P p[200005];
        for(int i = 0; i < n; i++){
            ll v;
            cin >> v;
            p[i] = P(v, i);
        }
        sort(p, p + n, greater<P>());
        vector<int> ans;
        ll s = 0;
        for(int i = 0; i < n; i++){
            if(s + p[i].first <= w){
                s += p[i].first;
                ans.push_back(p[i].second);
            }
        }
        if(s >= (w + 1) / 2){
            cout << (int)ans.size() << endl;
            for(int i : ans) cout << i + 1 << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }
}