#include<bits/stdc++.h>
using namespace std;
int n;
int x[200009],y[200009];
vector<pair<int,int> > v,w;
void booya(){
    w = v;
    sort(w.begin(),w .end());
    int c = 1;
    for(int i = 0; i < w.size(); i++){
        if(i && w[i].first != w[i-1].first) c++;
     //   cout<<c<<" "<<w[i].second<<endl;
        v[w[i].second-1].first = c;
    }
}
int g[200009],F[200009];
vector<int> f[200009];
void upd(int x){
    if(g[x]) return;
    g[x] =1;
    while(x <= n)
    F[x] ++, x+= (x&-x);
}
int cnt(int x){
    int ans = 0;
    while(x)
        ans+=F[x],
        x-=(x&-x);
    return ans;
}
long long C[200009];
main(){
   cin >> n;
   long long ans = 0;
   for(int i = 1; i <= n; i++)
    C[i] = C[i-1]+ i ;
   for(int i = 1; i <= n; i++){
     cin >> x[i] >> y[i];
   }
   for(int i= 1; i <= n; i++){
        v.push_back({x[i],i});
   }
   booya();
   for(int i = 1; i <= n; i++)
    x[i] = v[i-1].first;
   v.clear();
   for(int i= 1; i <= n; i++){
        v.push_back({y[i],i});
   }
   booya();
   for(int i = 1; i <= n; i++)
    y[i] = v[i-1].first;
    for(int i = 1; i <= n; i++)
        f[y[i]].push_back(x[i]);
    for(int i =n; i >= 1; i--){
        if(!f[i].size()) continue;
        sort(f[i].begin(),f[i].end());
        for(int j=  1; j < f[i].size(); j++)
            ans -= C[max(0,cnt(f[i][j]-1) - cnt(f[i][j-1]))];
        ans -= C[max(0,cnt(f[i][0]-1))];
        ans -= C[max(0, cnt(n) - cnt(f[i].back()))];
        for(int j : f[i])
            upd(j);
        ans += C[cnt(n)];
    }
    cout<<ans<<endl;
}
//0