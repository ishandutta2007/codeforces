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

using namespace std;
void solve(){
    int n;
    cin >> n;
    list<int> lst;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        lst.push_back(a);
    }
    int k = 0;
    vector<int> ans;
    while(!lst.empty()){
        if(k % 2 == 0){
            ans.push_back(lst.front());
            lst.pop_front();
        }else{
            ans.push_back(lst.back());
            lst.pop_back();
        }
        k++;
    }
    for(auto i : ans)
        cout << i << ' ';
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