#include<bits/stdc++.h>
using namespace std;
int p[100009];
int sg[100009];
int le[100009],ri[100009];
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        if(p[i] > p[i-1]) sg[i] = 1;
        else sg[i] = -1;

    }
    le[1] = 1;
    for(int i = 2; i <= n; i++){
        if(sg[i] == 1) le[i] = le[i-1] + 1;
        else le[i] = 1;
    }
    ri[n]  =1;
    for(int i = n-1; i >= 1; i --){
        if(sg[i+1] == -1) ri[i] = ri[i+1] + 1;
        else ri[i]  =1;
    }
    int mx = 0, nu = 0;
    for(int i = 1; i <= n; i++){
        if(le[i] > mx) nu = 1, mx = le[i];
        else if(le[i] == mx) nu++;
        if(ri[i] > mx) nu =1, mx = ri[i];
        else if(ri[i] == mx) nu++;
    }
    int ans = 0;

    for(int i = 2; i < n; i++){
        if(sg[i] != 1 || sg[i+1] != -1) continue;
        int cn = 0;
        if(le[i] == mx) cn++;
        if(ri[i] == mx) cn++;
        if(cn < nu) continue;
        if(le[i] > ri[i] - ri[i]%2 && ri[i] > le[i] - le[i]%2) ans++;
    }
    cout<<ans<<endl;
}