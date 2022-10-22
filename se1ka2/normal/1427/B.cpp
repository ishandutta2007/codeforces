#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v;
        bool f = false;
        int c = 0;
        int e = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'W'){
                ans++;
                if(f) v.push_back(c);
                else e += c;
                f = true;
                c = 0;
            }
            else c++;
        }
        if(!f){
            if(k == 0) cout << 0 << endl;
            else cout << k * 2 - 1 << endl;
            continue;
        }
        e += c;
        sort(v.begin(), v.end());
        for(int x : v){
            if(x <= k){
                ans += x * 2 + 1;
                k -= x;
            }
            else{
                ans += k * 2;
                k = 0;
            }
        }
        if(k) ans += min(k, e) * 2;
        cout << ans << endl;
    }
}