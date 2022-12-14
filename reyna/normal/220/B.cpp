//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
int arr[Maxn];
map<int,int> cnt,in;
int ins;
vector<int> oc[Maxn];
vector<int> nice;
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        cnt[arr[i]]++;
        if(cnt[arr[i]] == arr[i]) nice.push_back(arr[i]),in[arr[i]] = ++ins;
    }
    for(int i = 0; i < n;i++){
        if(in[arr[i]]) oc[in[arr[i]]-1].push_back(i);
    }
    for(int i = 0; i < m;i++){
        int l,r;
        cin >> l >> r;
        --l,--r;
        int ans = 0;
        for(int j = 0; j < nice.size();j++){
            int x = nice[j];
            int pl = lower_bound(oc[j].begin(),oc[j].end(),l)-oc[j].begin();
            int pr = upper_bound(oc[j].begin(),oc[j].end(),r)-oc[j].begin();
            if(pr - pl == x) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}