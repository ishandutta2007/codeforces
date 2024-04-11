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
    int n;
    cin >> n;
    vector<int> lst(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }
    int last = 0;
    while(!lst.empty()){
        vector<int> newlst;
        int elem = -1, pos = -1;
        for (int i = 0; i < lst.size(); ++i) {
            if(__gcd(last, lst[i]) > elem){
                elem = __gcd(last, lst[i]);
                pos = i;
            }
        }
        for (int i = 0; i < lst.size(); ++i) {
            if(i != pos)
                newlst.push_back(lst[i]);
        }
        last = elem;
        cout << lst[pos] << ' ';
        lst = newlst;
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}