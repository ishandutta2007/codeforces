#include<bits/stdc++.h>
using namespace std;
int a[100009];
        int n, l;
double t1(double x){
    double pas = 0;
    for(int i = 1; i <= n+1; i++){
        if(x <= a[i]) return pas + 1.0 * (x - a[i-1]) / i;
        pas +=1.0 * (a[i] - a[i-1]) / i;
    }
}
double t2(double x){
    double pas = 0;
    for(int i = n; i >= 0; i--){
        if(x >= a[i]) return pas + 1.0 * (a[i+1] - x) / (n -i + 1);
        pas +=1.0 * (a[i+1] - a[i]) / (n-i+1);
    }
}
main(){
    int t;
    cin>>t;
    while(t--){

        cin >> n >> l;
        int t = 1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        a[n+1] = l;
        double lo = 0, hi = l;
        while(hi - lo > 1e-6){
            double mid = (lo + hi)/2;
            if(t1(mid) < t2(mid)) lo = mid;
            else hi = mid;
        }
        printf("%9f\n", t1(lo));

    }

}