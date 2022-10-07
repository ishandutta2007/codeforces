#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[5009],b[5009];
main(){
    cin >> n >> m;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(long long i = 0; i < n; i++){
        cin >> b[i];
        if(b[i] == 1){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<double> V;
    V.push_back(a[0]);
    for(long long i = 1;i  < n ;i++)
        V.push_back(b[i]), V.push_back(a[i]);
    V.push_back(b[0]);
    double lo = 0, hi = 1e9;
    while(hi - lo > 1e-8){
        double mid = (lo+hi)/2;
        long long fl = 1;
        double x = mid;
        for(long long i = 0; i < V.size(); i++){
            x = (x*(V[i] - 1) - (double)m)/V[i];
            if(x < 0){
                fl = 0;
                break;
            }
        }
        if(x < 0) fl =0;
        if(fl) hi = mid;
        else lo = mid;
    }
    printf("%.9f\n",lo);
}