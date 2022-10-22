#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main()
{
    ll n;
    cin >> n;
    vector<int> ans;
    ll s = 1;
    for(int i = 1; i < n - 1; i++){
        if(gcd(n, i) == 1){
            ans.push_back(i);
            s = s * i % n;
        }
    }
    if(s == n - 1) ans.push_back(n - 1);
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;
}