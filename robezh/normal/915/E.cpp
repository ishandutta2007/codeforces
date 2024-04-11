#include <bits/stdc++.h>
using namespace std;

int n,q;
map<int, int> mp;
int sum;

int main(){
    scanf("%d%d", &n, &q);
    mp[n] = 1;
    sum = n;
    while(q--){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        for(auto it = mp.lower_bound(l); it != mp.end();){
            int il = it -> second, ir = it -> first;
            if(il > r) break;
            it = mp.erase(it);
            if(il < l) mp[l-1] = il; if(ir > r) mp[ir] = r+1;
            sum -= min(ir, r) - max(il, l) + 1;
        }
        if(k == 2) mp[r] = l, sum += (r - l + 1);

        printf("%d\n", sum);
    }
}