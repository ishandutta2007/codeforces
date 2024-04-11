#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int> M;
int ans[200009];
set<pair<int,int> > kn;
set<int> dv;
int n;
pair<int,int> query(int l , int r){
    cout<<"? "<< l<<" "<<r<<endl;
    int a, b;
    cin >>a;
    if(a == -1) exit(0);
    cin >> b;
    if(b == -1) exit(0);
    return make_pair(a,b);
}
main(){
    cin >> n;
    /*
    1 2 2 2 2 2 2 3
    */
    int s = 1, v = -1;
    while(s <= n){
        while(dv.size() && *dv.begin() < s) dv.erase(dv.begin());
        if(v == -1) v = query(s,s).first;
        if(M[v]){
            kn.erase(kn.find({M[v],v}));
            for(int i = s; i < s + M[v]; i++)
                ans[i] = v;
            s += M[v];
            v = -1;
            continue;
        }
        else{
            auto l = n - s + 1;
            if(kn.size()) l = kn.begin()->first;
            int L = n;
            if(dv.size()) L = *dv.begin();
            int r = min(L, s + l - 1);
            auto X = query(s, r);
            if(X.first == v){

                for(int i = s; i < s + X.second; i++)
                    ans[i] = v;
                s += X.second;
                v = -1;
                continue;
            }
            if(query(r, r).first == X.first){
                dv.insert(r - X.second);
                continue;
            }
            else{
                M[X.first] = X.second;
                kn.insert({X.second, X.first});
                continue;
            }
        }

    }

    cout<<"! ";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout<<endl;
}