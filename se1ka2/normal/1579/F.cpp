#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        int a[1000005];
        for(int i = 0; i < n; i++) cin >> a[i];
        bool b[1000005];
        for(int i = 0; i < n; i++) b[i] = false;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(b[i]) break;
            vector<int> v;
            int u = i;
            while(!b[u]){
                b[u] = true;
                v.push_back(a[u]);
                u = (u + d) % n;
            }
            int c = 0;
            int d = 0;
            for(int x : v){
                if(x) c++;
                else c = 0;
                d = max(c, d);
            }
            for(int x : v){
                if(x) c++;
                else c = 0;
                d = max(c, d);
            }
            if(d >= (int)v.size()) ans = -1;
            if(ans >= 0) ans = max(ans, d);
        }
        cout << ans << endl;
    }
}