#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    vector<bool> b(n, false);
    int ans = 0;
    bool flag = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] <= l){
            flag = true;
        }
        else{
            ans += flag;
            flag = false;
            b[i] = true;
        }
    }

    for(int i = 0; i < m; i++){
        int beh;
        cin >> beh;
        if(beh == 0)cout << ans << endl;
        else{
            int p, d;
            cin >> p >> d;
            p--;
            if(b[p])continue;
            if(a[p] + d <= l)a[p] += d;
            else{
                bool b1 = false, b2 = false;
                b[p] = true;
                if(p > 0)b1 = b[p - 1];
                if(p < n - 1)b2 = b[p + 1];
                if(b1 && b2)ans--;
                else if(b1 || b2);
                else ans++;
                
            }
        }
    }

}