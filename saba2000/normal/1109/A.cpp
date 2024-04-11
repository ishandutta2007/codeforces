#include<bits/stdc++.h>
using namespace std;
long long v[3000009][2];
int a[300009],s[300009];
main(){
    int n;
    cin >> n;
    v[0][0]++;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] ^ a[i];
        v[s[i]][i%2] ++;
    }
    long long ans = 0;
    for(int i = 0; i < (1<<20); i++){
        ans += v[i][0] * (v[i][0] - 1)/2 + v[i][1]*(v[i][1]-1)/2;
    }
    cout<<ans<<endl;

}