#include<bits/stdc++.h>
#define ll long long
#define fr first
#define se second
using namespace std;
main(){
    set<int>A,B;
    int n, m,a,b,v;
    cin >> n >> m>>a>>b>>v;
    for (int i = 0; i < a; i++){
       int x;
       cin >> x;
       A.insert(x);
    }
    for (int i = 0; i < b; i++){
       int x;
       cin >> x;
       B.insert(x);
    }
    int q;
    cin >> q;
    while(q--){
        int ans= 1e9;
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        if(y1 == y2) {
            cout<<abs(x2-x1)<<endl;
            continue;
        }
        int S = (abs(y2-y1));
        int E = (S+v-1)/v;
        auto it = B.lower_bound(x1);
        if(it != B.end()){
            int X = (*it);
            ans = abs(X-x1)+ abs(X-x2) + E;
        }
        if(it!=B.begin()){
            it--;
            int X = (*it);
            ans = min(ans,abs(X-x1)+ abs(X-x2) + E);
        }
        it = A.lower_bound(x1);
        if(it != A.end()){
            int X = (*it);
            ans = min(ans,abs(X-x1)+ abs(X-x2) + S);
        }
        if(it!=A.begin()){
            it--;
            int X = (*it);
            ans = min(ans,abs(X-x1)+ abs(X-x2) + S);
        }
        cout<<ans<<endl;

    }
}