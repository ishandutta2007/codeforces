#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
void solve(int TC) {
    string s;
    cin >> s;
    int pt1 = s.length() - 1;
    while(pt1 >= 0 && s[pt1] != '0') pt1--;   
    int pt2 = s.length() - 1;
    while(pt2 >= 0 && s[pt2] != '5') pt2--;

    int pt3 = pt1 - 1, pt4 = pt1 - 1;   
    int pt5 = pt2 - 1, pt6 = pt2 - 1;   
    while(pt3 >= 0 && s[pt3] != '0') pt3--;   
    while(pt4 >= 0 && s[pt4] != '5') pt4--; 
    while(pt5 >= 0 && s[pt5] != '2') pt5--;   
    while(pt6 >= 0 && s[pt6] != '7') pt6--;   
    cout << s.length() - 2 - max(max(pt3, pt4), max(pt5, pt6)) << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}