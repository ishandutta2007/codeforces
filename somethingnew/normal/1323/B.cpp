#include <iostream>
#include <vector>
#include "algorithm"
#include <iomanip>
#include "cmath"
using namespace std;
vector<int> deli(long long x){
    vector<int> dd;
    for (int i = 1; i < (int)sqrt(x) + 1; ++i) {
        if(x % i == 0){
            dd.push_back(i);
            if(x/i!=i){
                dd.push_back(x/i);
            }
        }
    }
    return dd;
}
int howm(vector<int> vec, int n){
    int ar = 0;
    int ans = 0;
    for (auto i : vec) {
        if(i == 1){
            ar++;
            if(ar >= n) ans++;
        }else{
            ar=0;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    long  long k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int ii = 0; ii < n; ++ii) {
        cin >> a[ii];
        //a[ii] = 1;
    }
    for (int jj = 0; jj < m; ++jj) {
        cin >> b[jj];
        //b[jj] = 1;
    }
    long long ans = 0;
    for(auto i : deli(k)){
        ans += (long long)howm(a,i) * (long long)howm(b,k/i);
    }
    cout << ans;
}