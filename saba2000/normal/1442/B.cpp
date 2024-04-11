#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009],b[200009],c[200009],p[200009],f[200009];
ll mod = 998244353;
main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i =1; i <= n; i++){
            cin >> a[i];
            f[i] = 0;
            p[a[i]] = i;
        }
        for(int i =1; i <= k; i++){
            cin >> b[i];
            c[i] = p[b[i]];
            f[c[i]] = 1;
        }
        set<int> s;
        ll ans = 1;
        for(int i = 1; i <= n; i++){
            s.insert(i);
        }
        for(int i = 1; i <= k; i++){
            auto it = s.lower_bound(c[i]);
            ll N= 0 ;
            if(it != s.begin()){
                --it;
                if(!f[*it]) N++;
                ++it;
            }
            if(it != --s.end()){
                it++;
                if(!f[*it]) N++;
            }
            ans = ans * N % mod;
            s.erase(s.find(c[i]));
        }
        cout << ans << endl;
    }
}