#include<bits/stdc++.h>
#define ll long long
#define fr first
#define se second
#define pb push_back
using namespace std;
ll x[1009],y[1009];
ll v[1009];
main(){
    int n;
    cin >> n;
    for(int i =1; i <= n; i++){
        cin>>x[i]>>y[i];
        x[i] += 1e6+1; y[i] += 1e6+1;
        v[i] = x[i] +y[i];
    }
    while(1){
        int fl = 0, fu = 0;
        for(int i = 1; i <= n; i++){

            if(v[i] % 2 == 1) fl = 1;
            if(v[i] % 2 == 0) fu = 1;
        }
        if(fl && fu) break;
        for(int i = 1; i <= n; i++){
            ll X = x[i], Y = y[i];
            x[i] = (X+Y);
            y[i] = (X-Y);
            if(x[i] % 2 == 0) x[i] /=2, y[i]/=2;
            else x[i] = (x[i] +1)/2, y[i] = (y[i]+1)/2;
            v[i] = x[i]+y[i];
        }
    }
    int k = 0;
    for(int i =1 ; i <= n; i++)
        if(v[i]%2==0) k++;
    cout<<k<<endl;
    for(int i = 1; i <= n; i++){
        if(v[i]%2==0) cout<<i<<" ";
    }
    cout<<endl;

}