#include<bits/stdc++.h>
using namespace std;
int lef[1009], deg[1009];
vector<int>v[1009];
int lca(int x, int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int z;cin>>z;
    return z;
}
void ans(int x){
    cout<<"! "<<x<<endl;
}
void rem(int x){
    lef[x] = 0;
    for(int y: v[x])
        deg[y]--;

}
main(){
    int n;
    cin >> n;

    for(int i =1 ;i <= n-1; i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(int i = 1; i <= n; i++)
        lef[i] = 1;
    while(1){
        for(int j = 1; j <= n; j++){

            if(!lef[j]) continue;
            if(deg[j] == 0){
                ans(j); return 0;
            }
            vector<int> l, nl;
            for(int x : v[j]){
                if(lef[x] && deg[x] == 1)
                   l.push_back(x);
                if(lef[x] && deg[x] > 1)
                    nl.push_back(x);
                }
            if(l.size()== 0 || nl.size()>1) continue;
            if(l.size()>= 2){
                int x = l[0], y = l[1];
                int u = lca(x,y);
                if(u == x) {ans(x); return 0;}
                if(u == y) {ans(y); return 0;}
                rem(x); rem(y);
                break;
            }
            if(nl.size() == 0){
                int x = l[0], y = j;
                ans(lca(x,y));
                return 0;
            }
            int x = l[0], y = nl[0];
            int u = lca(x,y);
            if(u == j || u == x) {ans(u); return 0;}
            rem(j);
            rem(x);
            break;
        }

    }



}