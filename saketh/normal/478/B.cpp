#include <iostream>
using namespace std;

int P, T;

int main(){
    cin >> P >> T;

    long long max = P - (T-1);
    max = max * (max - 1) / 2;

    long long small = P / T;
    long long nbig = P % T, nsmall = T - nbig;

    long long min = nsmall * small * (small - 1) / 2;
    min += nbig * small * (small + 1) / 2;

    cout << min << " " << max << endl;
    return 0;
}