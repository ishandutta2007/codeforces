#include<bits/stdc++.h>
using namespace std;
map<long long,long long> M;
main(){
    long long n,m;
    cin>>n;
    long long ans =0;
    for(long long i = 0; i < n; i++){
        long long k,p;
        cin>>k>>p;
        M[k] = p;
        ans+=p;
    }
    cin>>m;
    for(long long i = 0; i < m; i++){
        long long k,p;
        cin>>k>>p;
        ans+=max((long long)0, p-M[k]);

    }
    cout<<ans<<endl;

}