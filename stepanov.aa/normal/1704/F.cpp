#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


#define ll long long


const ll inf = 2e18;
const ll mod = 998244353;


const int mxf = 400;
int n;
string s;
vector<int> a;
vector<int> dp;


int get_mex(vector<int> &a){
    vector<int> b(a.size() + 1, 0);
    for(auto t: a){
        if(t < b.size()){
            b[t] = 1;
        }
    }
    for(int i = 0; i < n; i += 1){
        if(b[i] == 0){
            return i;
        }
    }
}


void get_dp(int n){
    dp.resize(max(n + 1, 2));
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; i += 1){
        vector<int> t;
        t.reserve(mxf);
        for(int j = 0; i - j - 2 >= 0 && j < mxf; j += 1){
            t.push_back(dp[j] ^ dp[i - j - 2]);
        }
        dp[i] = get_mex(t);
    }
}


int32_t main(){
    if(1){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        a.resize(n);
        for(int i = 0; i < n; i += 1){
            a[i] = (s[i] == 'B');
        }
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i = 0; i < n; i += 1){
            if(a[i] == 0){
                cnt0 += 1;
            } else{
                cnt1 += 1;
            }
        }
        vector<int> b;
        get_dp(n);
        int cnt = 0;
        for(int i = 0; i < n; i += 1){
            if(i == n - 1 || a[i] == a[i + 1]){
                if(cnt != 0){
                    b.push_back(cnt + 1);
                }
                cnt = 0;
            } else{
                cnt += 1;
            }
        }
        ll x = 0;
        for(auto t: b){
            x ^= dp[t];
        }
        if(x != 0){
            cnt0 += 1;
        }
        if(cnt0 > cnt1){
            cout << "Alice" << "\n";
        } else{
            cout << "Bob" << "\n";
        }
    }
    return 0;
}