#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5, B = 60;
typedef long long ll;

int n;
ll b;
vector<ll> num[B], app[N], ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b;
        ll x = b; int cat = -1;
        while(x > 0){cat ++; x /= 2;}
        num[cat].push_back(b);
    }

    for(int i = B-1; i >= 0; i--){
        if(num[i].empty()) continue;
        int odd = 0;
        for(ll x : ans) if((x >> i) & 1) odd++;
//        cout << "i = " << i << " : " << num[i].size() << ", " << odd << endl;
        if(num[i].size() > odd + 1) return cout << "No" << endl, 0;

        int cur = 1;
        for(int j = 0; j < ans.size(); j++){
            if(((ans[j] >> i) & 1) && cur < num[i].size()) app[j].push_back(num[i][cur++]);
        }
        vector<ll> new_ans;
        new_ans.push_back(num[i][0]);
        for(int j = 0; j < ans.size(); j++){
            new_ans.push_back(ans[j]);
            while(!app[j].empty()){
                new_ans.push_back(app[j].back());
                app[j].pop_back();
            }
        }
        ans = new_ans;
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
}