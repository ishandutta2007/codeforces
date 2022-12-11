#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double ygol(double n, int l, int r){
    double res;
    double first  = ((l * 180 - 360) - (180 - 360 / n) * (l - 2)) / 2;
    double second = ((r * 180 - 360) - (180 - 360 / n) * (r - 2)) / 2;
    res = second - first;
    return res;
}

int main()
{
    double n, m;
    cin >> n >> m;
    double mx = 1000000;
    int res_l = 2, res_r = 3;
    for(int l = 2, r = 3; r <= n; ++r){

        while(l < r-1 && fabs(ygol(n, l, r) - m) > fabs(ygol(n, l+1, r) - m)){
            ++l;
        }
        if(mx > fabs(ygol(n, l, r) - m)){
            res_l = l;
            res_r = r;
            mx = fabs(ygol(n, l, r) - m);
        }
    }
    cout << res_l << " " << 1 << " " << res_r;
}