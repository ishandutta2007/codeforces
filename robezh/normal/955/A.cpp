#include <bits/stdc++.h>
using namespace std;

int hh,mm;
int h,d,c,n;
double res;

int main(){
    cin >> hh >> mm;
    cin >> h >> d >> c >> n;

    if(hh >= 20){
        res = (ceil((double)h / n)) * c * 0.8;
        cout << fixed << setprecision(10) << res;
        return 0;
    }
    double res1 = ceil((double)h / n) * c;
    double minto20 = (20 - hh) * 60 - mm;
    double res2 = ceil((h + minto20 * d) / n) * c * 0.8;
    res = min(res1, res2);
    cout << fixed << setprecision(10) << res;
}