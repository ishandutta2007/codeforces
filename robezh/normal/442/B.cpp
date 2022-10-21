#include <bits/stdc++.h>
using namespace std;

int n;
double num[105];

int main(){
    cin >> n;
    double res = 0, max1 = 0, max2 = 0;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num, num+n, greater<double>());
    res = num[0];
    for(int i = 1; i < n; i++){
        double ires = 0;
        for(int j = 0; j <= i; j++){
            double pro = 1;
            for(int k = 0; k <= i; k++){
                if(k == j) pro *= num[k];
                else pro *= (1-num[k]);
            }
            ires += pro;
        }
        res = max(res, ires);
    }
    cout << fixed << setprecision(10) << res << endl;
}