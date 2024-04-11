#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000009;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        k--;
        ll s[100005];
        s[n - 1] = s[n - 2] = 1;
        for(int i = n - 3; i >= 0; i--){
            s[i] = min(s[i + 1] * 2, INF);
        }
        set<int> st;
        for(int i = 1; i <= n; i++) st.insert(i);
        int ans[100005];
        bool f = true;
        for(int i = 0; i < n; i++){
            if(s[i] > k){
                ans[i] = *st.begin();
                st.erase(st.begin());
            }
            else{
                int j;
                for(j = i; j < n; j++){
                    if(k >= s[j]) k -= s[j];
                    else break;
                }
                if(j == n){
                    f = false;
                    break;
                }
                for(int l = j; l >= i; l--){
                    ans[l] = *st.begin();
                    st.erase(st.begin());
                }
                i = j;
            }
        }
        if(!f) cout << -1 << endl;
        else{
            for(int i = 0; i < n; i++) cout << ans[i] << " ";
            cout << endl;
        }
    }
}