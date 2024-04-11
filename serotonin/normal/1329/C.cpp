#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1<<21;

int a[sz], b[sz], mp[sz];

int cut(int x)
{
    int pos = mp[x];
    int l = pos << 1, r = l + 1;
    if(!a[l] && !a[r]) return pos;
    cut(max(a[l], a[r]));
}

void got(int x)
{
    int pos = mp[x];
    int l = pos << 1, r = l + 1;
    if(!a[l] && !a[r]) a[pos] = 0;
    else a[pos] = max(a[l], a[r]);

    if(a[pos]) {
        got(a[pos]);
        mp[a[pos]] = pos;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int h, g;
        scanf("%d %d", &h, &g);

        for(int i=1; i<(1<<h); i++) {
            scanf("%d", &a[i]);
            mp[a[i]] = i;
            b[i] = a[i];
        }

        sort(b+1, b+(1<<h), greater<int>());

        ll tot = 0;
        vector <int> ans;
        int j = (1<<h)-(1<<g);
        for(int i=1; i<(1<<h); i++) {
            int where = cut(b[i]);

            if(j && where >= (1<<g)) {
                ans.push_back(mp[b[i]]);
                got(b[i]);
                j--;
            }
            else tot += b[i];
        }

        for(int i=1; i<(1<<h); i++) a[i] = 0;

        printf("%lld\n", tot);
        for(auto x : ans) printf("%d ", x);
        puts("");
    }
}