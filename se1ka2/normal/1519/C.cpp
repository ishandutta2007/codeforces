#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

vector<ll> v[200005];
vector<ll> s[200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            v[i].clear();
            s[i].clear();
        }
        int u[200005];
        for(int i = 0; i < n; i++){
            cin >> u[i];
            u[i]--;
        }
        for(int i = 0; i < n; i++){
            ll s;
            cin >> s;
            v[u[i]].push_back(s);
        }
        for(int i = 0; i < n; i++) sort(v[i].begin(), v[i].end(), greater<ll>());
        for(int i = 0; i < n; i++){
            s[i].push_back(0);
            for(int j = 1; j <= (int)v[i].size(); j++) s[i].push_back(s[i][j - 1] + v[i][j - 1]);
        }
        set<int> st;
        for(int i = 0; i < n; i++) st.insert(i);
        for(int k = 1; k <= n; k++){
            ll ans = 0;
            auto itr = st.begin();
            while(itr != st.end()){
                int i = *itr;
                itr++;
                int l = v[i].size();
                if(l < k) st.erase(i);
                else ans += s[i][l / k * k];
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}