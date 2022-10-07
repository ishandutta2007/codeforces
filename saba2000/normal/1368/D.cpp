#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v[200009];
int a[200009];
main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 20; j++){
            v[j].push_back({(a[i] & (1<<j) ? 1 : 0)});
        }
    }
    for(int i = 0; i < 20; i++)
        sort(v[i].begin(), v[i].end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll x  = 0;
        for(int j = 0; j < 20; j++){
            if(v[j][i]) x += (1<<j);
        }
        ans += x*x;

    }
    cout<<ans<<endl;

}
/*
XXXXXX
 X
XXXXXX
 X
XXXXXX

*/