#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    long double q=20000000000, p, l=0,r=q,m,t;
    cin>>n>>p;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for(int i=0;i<100;i++){
        m=(l+r)/2;
        t=0;
        for(int j=0;j<n;j++){
            if(m*a[j]>b[j])
                t+=m*a[j]-b[j];
        }
        if(t<=m*p) l=m;
        else r=m;
    }
    if (l<q-1000) cout<<fixed<<setprecision(10)<<l;
    else cout<<-1;
    return 0;
}