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
    int n, m;
    cin >> n >> m;
    vector<string> lst;
    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        lst.push_back(w);
    }
    vector<vector<int>> cul(n, vector<int>(m,0));
    vector<vector<int>> cur(n, vector<int>(m,0));
    vector<vector<int>> cdl(n, vector<int>(m,0));
    vector<vector<int>> cdr(n, vector<int>(m,0));
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if(lst[i][j] == lst[i-1][j] and lst[i][j] == lst[i][j-1]){
                cul[i][j] = 1 + min(cul[i-1][j], cul[i][j-1]);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = m - 2; j > -1; --j) {
            if(lst[i][j] == lst[i-1][j] and lst[i][j] == lst[i][j+1]){
                cur[i][j] = 1 + min(cur[i-1][j], cur[i][j+1]);
            }
        }
    }
    for (int i = n - 2; i > -1; --i) {
        for (int j = 1; j < m; ++j) {
            if(lst[i][j] == lst[i+1][j] and lst[i][j] == lst[i][j-1]){
                cdl[i][j] = 1 + min(cdl[i+1][j], cdl[i][j-1]);
            }
        }
    }
    for (int i = n - 2; i > -1; --i) {
        for (int j = m - 2; j > -1; --j) {
            if(lst[i][j] == lst[i+1][j] and lst[i][j] == lst[i][j+1]){
                cdr[i][j] = 1 + min(cdr[i+1][j], cdr[i][j+1]);
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res += 1 + min(min(cul[i][j], cur[i][j]), min(cdl[i][j], cdr[i][j]));
        }
    }
    cout << res;
}