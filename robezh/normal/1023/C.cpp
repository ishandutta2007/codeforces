#include <bits/stdc++.h>
using namespace std;

int n, k;
string s, res;

int main() {
    cin >> n >> k;
    k /= 2;
    cin >> s;
    int l = 0, bl = 0;
    for(char c : s){
        if(c == '('){
            if(l < k){
                res.push_back(c);
                l++;
                bl++;
            }
        }
        else{
            if(bl > 0){
                res.push_back(c);
                bl--;
            }
        }
    }
    cout << res << endl;


}