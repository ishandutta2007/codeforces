#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int main()
{
    int n, q;
    cin >> n >> q;
    int p[100005];
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    int d = p[n - 1] - p[0];
    set<PP, greater<PP>> st;
    for(int i = 1; i < n; i++){
        st.insert(PP(p[i] - p[i - 1], P(p[i - 1], p[i])));
    }
    map<P, int> mp;
    for(int i = 1; i < n; i++){
        mp[P(p[i - 1], p[i])] = p[i] - p[i - 1];
    }
    q++;
    bool f = true;
    int left = p[0];
    while(q--){
        if(st.empty()) cout << 0 << endl;
        else cout << d - st.begin()->first << endl;
        if(q == 0) break;
        int t, x;
        cin >> t >> x;
        if(t){
            if(st.empty()){
                if(f){
                    if(x < left) swap(x, left);
                    mp[P(left, x)] = x - left;
                    st.insert(PP(x - left, P(left, x)));
                    d = x - left;
                }
                else{
                    f = true;
                    left = x;
                }
                continue;
            }
            int l = mp.begin()->first.first;
            int r = (--mp.end())->first.second;
            if(x < l){
                mp[P(x, l)] = l - x;
                st.insert(PP(l - x, P(x, l)));
                d += l - x;
                left = x;
            }
            else if(x > r){
                mp[P(r, x)] = x - r;
                st.insert(PP(x - r, P(r, x)));
                d += x - r;
            }
            else{
                auto itr = --mp.lower_bound(P(x, x));
                l = itr->first.first, r = itr->first.second;
                st.erase(PP(itr->second, itr->first));
                mp.erase(itr);
                mp[P(l, x)] = x - l;
                mp[P(x, r)] = r - x;
                st.insert(PP(x - l, P(l, x)));
                st.insert(PP(r - x, P(x, r)));
            }
        }
        else{
            if(mp.empty()){
                f = false;
                continue;
            }
            auto itr = mp.lower_bound(P(x, x));
            if(itr == mp.end()){
                itr--;
                int l = itr->first.first;
                st.erase(PP(itr->second, itr->first));
                mp.erase(itr);
                d -= x - l;
            }
            else if(itr == mp.begin()){
                int r = itr->first.second;
                st.erase(PP(itr->second, itr->first));
                mp.erase(itr);
                d -= r - x;
                left = r;
            }
            else{
                int r = itr->first.second;
                st.erase(PP(itr->second, itr->first));
                auto itr2 = itr;
                itr--;
                mp.erase(itr2);
                int l = itr->first.first;
                st.erase(PP(itr->second, itr->first));
                mp.erase(itr);
                st.insert(PP(r - l, P(l, r)));
                mp[P(l, r)] = r - l;
            }
        }
    }
}