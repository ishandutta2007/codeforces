#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    ll p[62];
    p[0] = 2;
    for(int i = 1; i <= 60; i++) p[i] = p[i - 1] * 2 + 2;
    while(t--){
        ll k;
        cin >> k;
        if(k & 1){
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        ans.push_back(1);
        k -= 2;
        while(k){
            int l = upper_bound(p, p + 61, k) - p - 1;
            for(int i = 0; i < l; i++) ans.push_back(0);
            ans.push_back(1);
            k -= p[l];
        }
        cout << (int)ans.size() << endl;
        for(int i : ans) cout << i << " ";
        cout << endl;
    }
}