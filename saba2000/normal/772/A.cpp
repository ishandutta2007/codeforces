#include<bits/stdc++.h>
using namespace std;
main(){
    long long n;
    double p, S = 0;
    cin >> n >> p;
    vector<pair<double,long long> >v;
    for (long long i = 0 ; i < n; i++){
        long long a,b;
        cin >>a >> b;
        S += a;
        v.push_back({1.0*b/a,a});
    }
    if(p >= S) {
        cout << -1 << endl;
        return 0;
    }
    sort(v.begin(),v.end());
    double T = 0;
    for (long long i = 0 ; i < v.size() - 1; i++){
        v[i+1].first -= T;
        double t1 = v[i].first,t2=v[i+1].first;
        double a1= v[i].second, a2=v[i+1].second;
        double t3 = (t2-t1)*a1/p;
        if( p < a1){
            double t4 = t1*a1/(a1 - p);
            if (t4 < t3){
                printf("%.9f",T+t4);
                return 0;
            }
        }
        v[i+1].first -= t3;
        T += t3;
        v[i+1].second += v[i].second;
    }
    printf("%.9f",T+v.back().first*v.back().second/(v.back().second-p));
}