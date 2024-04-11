#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int a[N],b[N];
int f[N];
main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1 ;i <= n; i++)
        cin>>a[i];
    long long ans  = 1;
    if(n > m)cout<<0;
    else{
        for(int i =1; i <= n; i++)
            for(int j = i+1; j <= n; j++)
                ans = ans * (abs(a[i] - a[j])%m)%m;

    cout<<ans<<endl;}



}