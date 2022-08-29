#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1001;
bitset<250000 + 1> bs[500 + 1];
int l[maxn], p[maxn];
int R[maxn], D[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int h, suml = 0, sump = 0;
        cin >> h;
        for(int i = 1; i <= h; i += 1){
            R[i] = 0;
            cin >> l[i];
            suml += l[i];
        }
        sort(l + 1, l + h + 1, greater<int>());
        int v;
        cin >> v;
        for(int i = 1; i <= v; i += 1){
            D[i] = 0;
            cin >> p[i];
            sump += p[i];
        }
        sort(p + 1, p + v + 1);
        if(h != v or h == 1 or (suml & 1) or (sump & 1)){
            cout << "No\n";
            continue;
        }
        bs[0].set(0);
        for(int i = 1; i <= h; i += 1) bs[i] = bs[i - 1] | (bs[i - 1] << l[i]);
        if(not bs[h].test(suml / 2)){
            cout << "No\n";
            continue;
        }
        int x = suml / 2;
        for(int i = h; i; i -= 1)
            if(bs[i - 1].test(x)) R[i] = 1;
            else x -= l[i];
        
        bs[0].set(0);
        for(int i = 1; i <= v; i += 1) bs[i] = bs[i - 1] | (bs[i - 1] << p[i]);
        if(not bs[v].test(sump / 2)){
            cout << "No\n";
            continue;
        }
        int y = sump / 2;
        for(int i = v; i; i -= 1)
            if(bs[i - 1].test(y)) D[i] = 1;
            else y -= p[i];
        cout << "Yes\n";
        vector<int> sp, sz;
        {
            int cntp=0,cntz=0;
            for(int i = 1; i <= h; i += 1) if(R[i]) ++cntp;
            for(int i = 1; i <= v; i += 1) if(D[i]) ++cntz;
            if(cntp>h-cntp)
                for(int i = 1; i <= h; i += 1) R[i]^=1;
            if(cntz<v-cntz)
                for(int i = 1; i <= v; i += 1) D[i]^=1;
        }
        for(int i = 1; i <= h; i += 1) if(R[i]) sp.push_back(i);
        for(int i = 1; i <= h; i += 1) if(not R[i]) sp.push_back(i);
        for(int i = 1; i <= v; i += 1) if(D[i]) sz.push_back(i);
        for(int i = 1; i <= v; i += 1) if(not D[i]) sz.push_back(i);
        x = 0, y = 0;
        for(int i = 0; i < h; i += 1){
            cout << x << " " << y << "\n";
            if(R[sp[i]]) x += l[sp[i]];
            else x -= l[sp[i]];
            cout << x << " " << y << "\n";
            if(D[sz[i]]) y -= p[sz[i]];
            else y += p[sz[i]];
        }
    }
    return 0;
}