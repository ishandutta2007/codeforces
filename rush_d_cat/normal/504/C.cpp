#include <iostream>
using namespace std;
const int NICO = 100000+10;
typedef long long LL;
int n, a[NICO], cnt[NICO], tmp[NICO]; LL ans = 0;

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }

    int len = 0;
    for(len = 0; a[len] == a[n-len+1] && len <= n; len ++) {}
    -- len;
    //cout << len << endl;
    if(len == n) {
        ans = (LL)n*(n+1)/2;
        cout << ans << endl; return 0;
    }

    LL ans1 = 1, ans2 = 1; // [len+1, n-len]
    for(int i=len+1;i<=n-len;i++) 
        cnt[a[i]] ++;
    
    int odd = 0;
    for(int i=1;i<=n;i++) if(cnt[i]%2)
        odd ++;

    if(odd >= 2) {
        ans = 0;
    } else {

        ans = len * len;
        for(int i=1;i<=n;i++) tmp[i]=cnt[i];

        for(int i=n-len;i>=len+1;i--) {
            if( (n-len)-i < i-(len+1) ) {
                cnt[a[i]] -= 2; 
                if(cnt[a[i]] < 0) {
                    break;
                }
            }

            if( (n-len)-i == i-(len+1) ) {
                if(!(cnt[a[i]] % 2)) {
                    break;
                }
                cnt[a[i]] -= 1; 
            }            

            if( (n-len)-i > i-(len+1) ) {
                if(a[i] != a[n+1-i]) {
                    break;
                }
            }

            ans1 ++;
        }
        
        //cout << ans1 << endl;
        
        ans += ans1 * (len + 1);
        for(int i=1;i<=n;i++) cnt[i]=tmp[i];

        for(int i=len+1;i<=n-len;i++) {
            if( (n-len)-i > i-(len+1) ) {
                cnt[a[i]] -= 2; 
                if(cnt[a[i]] < 0) {
                    break;
                }
            }

            if( (n-len)-i == i-(len+1) ) {
                if(!(cnt[a[i]] % 2)) {
                    break;
                }
                cnt[a[i]] -= 1; 
            }            

            if( (n-len)-i < i-(len+1) ) {
                if(a[i] != a[n+1-i]) {
                    break;
                }
            }

            ans2 ++;
        }
        //cout << ans2 << endl;
        
        ans += ans2 * (len + 1);
        ans --;
    }

    cout << ans << endl;
}