#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int lh[200005], ll[200005];
        int lp[200005];
        int h = 0;
        lh[0] = 0, ll[0] = 0;
        lp[0] = 0;
        for(int i = 0; i <= n; i++){
            if(i > 0){
                lh[i] = max(lh[i - 1], h);
                ll[i] = min(ll[i - 1], h);
            }
            if(s[i] == '+') h++;
            else h--;
            lp[i + 1] = h;
        }
        int rh[200005], rl[200005];
        h = 0;
        rh[n] = 0, rl[n] = 0;
        for(int i = n; i > 0; i--){
            if(i < n){
                rh[i] = max(rh[i + 1], h);
                rl[i] = min(rl[i + 1], h);
            }
            if(s[i - 1] == '-') h++;
            else h--;
        }
        while(m--){
            int l, r;
            cin >> l >> r;
            l--;
            int low = min(ll[l], rl[r] + lp[n] - lp[r] + lp[l]);
            int high = max(lh[l], rh[r] + lp[n] - lp[r] + lp[l]);
            cout << high - low + 1 << endl;
        }
    }
}