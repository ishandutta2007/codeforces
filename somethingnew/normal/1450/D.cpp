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
    vector<int> lst(n);
    list<int> a;
    for(auto &i : lst){
        cin >> i;
        a.push_back(i);
    }
    vector<int> cnt(n + 1, 0);
    for(auto i : lst)
        cnt[i]++;
    vector<int> good(n + 1, 0);
    good[0] = true;
    for(int i = 1; i <= n; ++i){
        if(good[i-1])
            good[i] = (cnt[i] == 1);
    }
    vector<int> cando(n + 1, 0);
    cando[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if(a.front() == i){
            a.pop_front();
            cando[i] = 1;
        } else if (a.back() == i){
            a.pop_back();
            cando[i] = 1;
        }else{
            break;
        }
    }
    vector<int> ans(n, 0);
    ans[0] = good[n];
    for (int i = 1; i < n; ++i) {
        if(cando[n - 1 - i] and good[n - i - 1] and cnt[n - i])
            ans[i] = 1;
    }
    for(auto &i : ans)
        cout << i;
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}