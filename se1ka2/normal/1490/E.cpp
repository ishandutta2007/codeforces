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
        cin >> n;
        P p[200005];
        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            p[i] = P(a, i);
        }
        sort(p, p + n);
        ll s[200005];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + p[i - 1].first;
        vector<int> ans;
        ans.push_back(p[n - 1].second);
        for(int i = n - 2; i >= 0; i--){
            if(s[i + 1] >= p[i + 1].first) ans.push_back(p[i].second);
            else break;
        }
        sort(ans.begin(), ans.end());
        cout << (int)ans.size() << endl;
        for(int i : ans) cout << i + 1 << " ";
        cout << endl;
    }
}