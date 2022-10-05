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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
using namespace std;
int val(char s){
    return 1 << (s - 'a');
}
void solve(){
    int n, T;
    cin >> n >> T;
    string s;
    cin >> s;
    T -= val(s.back());
    s.pop_back();
    T += val(s.back());
    s.pop_back();
    sort(rall(s));
    for(auto i : s){
        int q = val(i);
        if(T > 0)
            T -= q;
        else
            T += q;
    }
    if(T == 0)
        cout << "YES";
    else
        cout << "NO";
}
signed main() {
    ios_base::sync_with_stdio(0);
    solve();
}