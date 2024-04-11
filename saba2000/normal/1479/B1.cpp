#include<bits/stdc++.h>
using namespace std;
int a[100009],f[100009];
vector<int> v[100009];
main(){
    int n;
    cin >> n;
    int ans = 0;
    int x = -1, y = -1;
    for(int i =1 ;i <= n; i++){
        cin >> a[i];
        if(a[i] == x && a[i] == y) continue;
        if(a[i] == x) y = a[i];
        else if(a[i] == y) x = a[i];
        else if(x != y) y = -1;
        x = a[i];
        ans++;
    }
    cout<<ans<<endl;

}
// 6
// x      ....xy
// y