#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[5009],y[5009],p[5009],f[5009];
ll d(int i, int j){
    return (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i])* (y[j] - y[i]);
}
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    f[1] =1;
    p[1] = 1;
    for(int t = 2; t <= n; t++){
        int m = p[t-1];
        for(int i = 1; i <= n; i++){
            if(f[i]) continue;
            if(d(p[t-1], m) < d(p[t-1], i)) m = i;
        }
        p[t] = m;
        f[m] = 1;
    }
    for(int i = 1; i <= n; i++){
        cout << p[i]<<" ";
    }
    cout<<endl;


}