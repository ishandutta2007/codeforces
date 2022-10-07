#include<bits/stdc++.h>
using namespace std;
int a[100009],f[100009];
vector<int> v[100009];
main(){
    int n;
    cin >> n;
    int ans = 0;
    int x = -1, y = -1, z = -1;
    set<int> s;
    int m = 0,t = 0;
    for(int i =1 ;i <= n; i++){
        cin >> a[i];
        if(a[i] == a[i-1]) continue;
        int x = f[a[i]];
        f[a[i]] = ++t;
        if(x > 0 && x >= m-1)
            m = t;
        else ans++;

    }
    cout<<ans<<endl;

}
//1 2 1 2