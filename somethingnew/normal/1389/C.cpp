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

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int maxres = 0;
    for (int l = 0; l < 10; ++l) {
        for (int r = 0; r < 10; ++r) {
            bool turn = true;
            int res = 0;
            for(auto i : s){
                if(i - '0' == l and turn){
                    turn = not turn;
                    res += 1;
                } else if(i - '0' == r and not turn){
                    turn = not turn;
                    res += 1;
                }
            }
            if(not turn and l != r) res-=1;
            maxres = max(res,maxres);
        }
    }
    cout << n - maxres << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}