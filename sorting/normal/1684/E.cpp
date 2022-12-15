#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        int diff = 0;
        map<int, int> cnt;
        multiset<int> s, s2;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(all(a));
        diff = cnt.size();
        for(auto [x, y]: cnt)
            s.insert(y);

        int real_k = k;
        while(real_k > 0 && !s.empty()){
            if((*s.begin()) > real_k)
                break;
            real_k -= *s.begin();
            s2.insert(*s.begin());
            s.erase(s.begin());
            --diff;
        }

        int ans = INT_MAX;
        int i;
        for(i = 0; k >= 0 && i <= cnt.rbegin()->first + 1; ++i){
            //cout << i << " - " << diff << "\n";
            check_min(ans, -i + diff);
            if(cnt[i]){
                if(s.count(cnt[i])){
                    s.erase(s.find(cnt[i]));
                }
                else{
                    s2.erase(s2.find(cnt[i]));
                    real_k += cnt[i];
                    ++diff;
                    while(real_k > 0 && !s.empty()){
                        if((*s.begin()) > real_k)
                            break;
                        real_k -= *s.begin();
                        s2.insert(*s.begin());
                        s.erase(s.begin());
                        --diff;
                    }
                }
                continue;
            }
            --k;
            ++diff;
        }
        // cout << i << " - " << diff << endl;

        cout << ans << "\n";
    }
}