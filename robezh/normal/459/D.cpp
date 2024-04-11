#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 500;
typedef pair<int, int> P;

int n;
int num[N], bit[N];
P l[N], r[N];

int get(int i){
    int ans = 0;
    while(i){ans += bit[i]; i -= (i&-i);}
    return ans;
}

int add(int i, int val){
    while(i < N){bit[i] += val; i += (i&-i);}
}

int main() {
    fill(bit, bit+N, 0);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);

    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        mp[num[i]]++;
        l[i].first = mp[num[i]];
        l[i].second = i;
    }
    mp.clear();
    for(int i = n; i >= 1; i--){
        mp[num[i]]++;
        r[i].first = mp[num[i]];
        r[i].second = i;
    }
    sort(l+1, l+n+1, greater<P>());
    sort(r+1, r+n+1, greater<P>());
    int pt = 1;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        while(pt <= n && l[pt].first > r[i].first){
            add(l[pt].second, 1);
            pt++;
        }
        res += (r[i].second == 1 ? 0 : get(r[i].second-1));
    }

    cout << res << endl;

}