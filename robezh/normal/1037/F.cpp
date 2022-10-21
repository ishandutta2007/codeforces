#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500, mod = (int)1e9 + 7;
typedef long long ll;
typedef pair<int, int> P;

int n,k;
P num[N];
ll sum[N];

bool cmp(P p1, P p2){
    return p1.first != p2.first ? p1.first > p2.first : p1.second > p2.second;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) sum[i] = (i - 1) / (k - 1) + 1;
    for(int i = 1; i <= n; i++) sum[i] += sum[i-1];
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i].first);
        num[i].second = i;
    }
    sort(num, num + n, cmp);
    set<int> S;
    ll res = 0;
    for(int i = 0; i < n; i++){
        int l,r,mid;
        mid = num[i].second;
        auto it = S.upper_bound(num[i].second);
        if(S.empty() || it == S.end()) r = n;
        else r = *it;
        if(S.empty() || it == S.begin()) l = -1;
        else l = *(--it);

        res += (sum[r - l - 1] - sum[mid - l - 1] - sum[r - mid - 1] - 1) % mod * num[i].first % mod;
        res %= mod;

        S.insert(num[i].second);
    }
    cout << res << endl;

}