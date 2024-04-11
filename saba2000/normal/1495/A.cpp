#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>> n;
        vector<long double>a,b;
        for(int i = 1; i <= 2*n; i++){
            int x,y;
            cin>>x>>y;
            if(x==0) a.push_back(abs(y));
            else b.push_back(abs(x));
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long double ans = 0;
        for(int i = 0; i < n; i++)
            ans += sqrt(a[i]*a[i] + b[i]*b[i]);
        printf("%.9lf\n",(double)ans);

    }

}