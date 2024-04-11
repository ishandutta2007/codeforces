#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    int n;
    long long int first;
    long long int numlast;
    long long int numm;
    long long int zero = 0;
    long long int bullet = 0;
    long long int mina;
    long long int rrr;
    long long int arr;
    for (; t > 0 ; --t) {
        cin >> n;
        cin >> first;
        bullet = 0;
        mina = first;
        for (int i = 0; i < n - 1; ++i) {
            cin >> numlast;
            cin >> numm;
            arr = max(zero, numm - numlast);
            bullet = bullet + arr;
            mina = min(mina, numm - arr);
        }
        cin >> rrr;
        arr = max(zero, first - rrr);
        bullet = bullet + arr;
        mina = min(mina, first - arr);
        cout << bullet + mina << '\n';
    }
}