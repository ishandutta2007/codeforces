#include<bits/stdc++.h>
using namespace std;
int sz[1009];
int f[1009];
    int n, Ce,CC;
    vector<int> v[1009];
int szd(int x){
    sz[x] = 1;
    f[x] = 1;
    for(int y : v[x]){
        if(f[y]) continue;
        szd(y);
        sz[x] +=sz[y];
    }
}
int fnc(int x){
    f[x] = 1;
    for(int y : v[x])
        {
        if(f[y]) continue;
        if(sz[y] > n/2) return fnc(y);
    }
    return x;
}
int ff[1009];
void cl(){
    for(int i = 1; i <= n; i++)
        f[i] = 0;
}
void dfs(int x, int mu){
    f[x] = 1;
    CC++;
    int no = CC;
    for(int y : v[x]){
        if(f[y]) continue;

        cout << x <<" "<<y <<" "<<mu*(CC - no + 1) << endl;
        dfs(y, mu);
    }
}
void ass(int x, int mu, int ad){
    CC = 0;
    cout<<x<<" "<<Ce<<" "<<ad*mu<<endl;
    dfs(x, mu);
}
main(){
    cin >> n;
    for(int i =1 ;i <= n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    szd(1); cl();
    Ce = fnc(1); cl();
    f[Ce] = 1;
    vector<pair<int,int> > c;
    for(int x : v[Ce]){
        if(sz[x] <= sz[Ce]) c.push_back({sz[x], x});
        else c.push_back({n - sz[Ce], x});
    }
    sort(c.begin(), c.end());
    int T = 0;
    for(auto x : c){
        if(x.first >= n/3){
            int u = x.second;
            int C = 0;
            for(int x : v[Ce]){
                if(x != u) {
                    ass(x, 1, C+1);
                    C += CC;
                }
            }
            ass(u, C + 1, 1);
            return 0;
        }
        T += x.first;
        ff[x.second] = 1;
        if(T >= n/3 && T <= 2*n/3){
            int C = 0;
            for(int x : v[Ce]){
                if(ff[x]) {
                    ass(x, 1, C+1);
                    C += CC;
                }
            }
            int D = 0;
            for(int x : v[Ce]){
                if(!ff[x]) {
                    ass(x, C+1, D+1);
                    D += CC;
                }
            }
            return 0;
        }
    }


}