#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;

int gcd_ext(int a, int b, long long &x, long long &y){
    // ax + by = gcd(a, b); return gcd(a, b); x  y
    if(b == 0){
        x = 1;y=0;
        return a;
    }
    int d = gcd_ext(b,a%b,x,y);
    x -= y * (a/b);
    swap(x,y);
    return d;
}

signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n == 1){
        int k;
        cin >> k;
        cout << "1 1\n" << k << "\n1 1\n" << -k << "\n1 1\n" << -k;

        return 0;
    }
    vector<int> lst(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }
    vector<int> ans1(n,0), ans2(n-1, 0);
    for (int i = 0; i < n - 1; ++i) {
        long long x, y;
        gcd_ext(n,n-1,x,y);
        x *= n;
        y *= n-1;
        x *= -lst[i];
        y *= -lst[i];
        ans1[i] = x;
        ans2[i] = y;
    }
    cout << "1 " << n << endl;
    for(auto i : ans1) cout << i << ' ';
    cout << endl;
    cout << "1 " << n - 1 << endl;
    for(auto i : ans2) cout << i << ' ';
    cout << endl;
    cout << n << ' ' << n << endl << -lst[n-1] << endl;

}