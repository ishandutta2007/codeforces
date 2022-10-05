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

using namespace std;

int ans(string s, char c){
    if(s.size() == 1) return c != s[0];
    int n = s.size();
    int n1=0,n2=0;
    string s2,s1;
    for (int i = 0; i < s.size(); ++i) {
        if(i<n/2) {
            n1+= (s[i] != c);
            s2.push_back(s[i]);
        } else{
            n2 += (s[i] != c);
            s1.push_back(s[i]);
        }
    }
    return min(n1 + ans(s1,c+1), n2+ans(s2,c+1));
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << ans(s,'a') << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}