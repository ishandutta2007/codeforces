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
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int,int>> zp(n * 2, {0, 0});
    vector<int> p(n, 0);
    vector<pair<int,int>> sosedi(n * 2, {0, 0});
    for (int i = 0; i < n * 2; ++i) {
        sosedi[i] = {i-1, i + 1};
    }
    for (int i = 0; i < 2 * n;++i) {
        char k;
        cin >> k;
        if(k == '+'){
            zp[i] = {1, 0};
        }else{
            int b;
            cin >> b;
            zp[i] = {-1, b - 1};
            p[b-1] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        int k = p[i];
        int p2 = sosedi[k].first;
        if(p2 == -1){
            cout << "NO";
            return 0;
        }
        int t = zp[p2].first;
        if(t != 1){
            cout << "NO";
            return 0;
        }
        zp[p2].second = i;
        if(sosedi[p2].first != -1){
            sosedi[sosedi[p2].first].second = sosedi[k].second;
        }
        if(sosedi[k].second != n * 2){
            sosedi[sosedi[k].second].first = sosedi[p2].first;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < 2 * n; ++i) {
        if(zp[i].first == 1){
            cout << zp[i].second + 1 << ' ';
        }
    }
}