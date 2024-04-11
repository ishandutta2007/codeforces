#include<bits/stdc++.h>
using namespace std;
int f[300009][3];
int n,q;
void upd(int x, int t, int d){
    while(x <= n+100){
        f[x][t] += d;
        x += (x & -x);
    }
}
int cnt(int t, int x){
    int ans = 0;
    while(x){
        ans += f[x][t];
        x -= (x & -x);
    }
    return ans;
}
char F[10009];
int a[300009];
main(){ string s;
    F['R'] = 2;
    F['P'] = 1;
    F['S'] = 0;
    cin >> n >> q;
    cin >> s;
    set<int> S[3];
    for(int i = 1; i <= s.size(); i++){
        a[i] = F[s[i-1]];
        upd(i, a[i], 1);
        S[a[i]].insert(i);
    }
    do{
        int l[3], r[3];
        for(int i = 0; i < 3; i++){
            if(!S[i].size()) l[i] = 0, r[i] = 0;
            else{
                l[i] = *S[i].begin();
                r[i] = *(--S[i].end());
            }
        }
        int ans = 0;
        for(int i = 0; i< 3; i++){
            int O = (i + 1) % 3;
            int X = (i + 2) % 3;
            if(!l[X]) ans += cnt(i, n);
            else if(l[O]){
                ans += cnt(i, n);
                if(r[X] > r[O]) ans -= cnt(i, r[X]) - cnt(i, r[O]);
                if(l[O] > l[X]) ans -= cnt(i, l[O] - 1) - cnt(i, l[X] - 1);
            }


        }
        cout<<ans<<endl;
        if(q == 0) return 0;
        int p; char X;
        cin>>p>>X;
        upd(p, a[p], -1);
        S[a[p]].erase(S[a[p]].find(p));
        a[p] = F[X];
        upd(p, a[p], 1);
        S[a[p]].insert(p);
        // ....X...O......O....X....

    }while(q--);



}