#include<bits/stdc++.h>
using namespace std;
int f[1000009];
int a[100009];
main(){
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i = 1; i <= n; i++){
        int l;
        scanf("%d %d",&l,&a[0]);
        int yes = 1;
        for(int j = 1; j < l; j++){
            scanf("%d", &a[j]);
            if(a[j] > a[j-1]) yes = 0;
        }
        if(yes == 0) continue;
        v.push_back({a[l-1],a[0]});
        f[a[0]]++;

    }
    for(int i = 1; i <= 1e6; i++)
        f[i] += f[i-1];
    long long ans = (long long)n*n;
    for(int i = 0; i < v.size(); i++){
        ans -= f[v[i].first];
    }
    cout<<ans<<endl;
}