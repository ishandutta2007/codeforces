
#include<bits/stdc++.h>
using namespace std;
vector<int> w[100009];
long long l[100009],r[100009];
main(){
   int n, m;
   cin  >>n>> m;
   for(int i=1 ; i <= m ;i++){
        int a,b;
        cin >> a >> b;
        if(a < b) w[a].push_back(b);
        else w[b].push_back(a);
        if(a < b) r[a]++, l[b]++;
        else r[b]++, l[a]++;
   }
   long long ans  = 0;
   for(int i =1 ; i <= n; i++){
    ans += l[i]*r[i];
   }
   cout<<ans<<endl;
   int q;
   cin >> q;
   while(q--){
        int u;
        cin >> u;
        ans -= l[u]*r[u];
        l[u] += r[u]; r[u] = 0;
        for(int x : w[u]){
            w[x].push_back(u);
            ans -= r[x]  *l[x];
            r[x]++; l[x]--;
            ans += r[x]  *l[x];
            //(r[x]+1)(l[x]-1)
        }
        w[u].clear();
        cout<< ans<<endl;

   }

}