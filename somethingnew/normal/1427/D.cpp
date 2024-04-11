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
struct elem{
    int size, front, back;
};
elem un(elem a, elem b){
    elem c = {a.size + b.size, a.front, b.back};
    return c;
}
void solve(vector<elem> &lst, vector<vector<int>> &ans){
    int n = lst.size();
    for(int i = 0; i < n - 1; ++i) {
        if(lst[i].back + 1 == lst[i + 1].front){
            vector<elem> nl;
            nl.reserve(lst.size() - 1);
            for (int j = 0; j < i; ++j) {
                nl.push_back(lst[j]);
            }
            nl.push_back(un(lst[i], lst[i + 1]));
            for (int j = i + 2; j < n; ++j) {
                nl.push_back(lst[j]);
            }
            lst = nl;
            i--;
            n = lst.size();
        }
    }
    if(lst.size() == 1)
        return;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(lst[i].back + 1 == lst[j].front){
                vector<elem> nl;
                nl.reserve(lst.size());
                int seg4 = 0;
                for (int k = i + 1; k < n; ++k) {
                    seg4 += lst[k].size;
                    nl.push_back(lst[k]);
                }
                int seg3 = 0;
                for (int k = j + 1; k <= i; ++k) {
                    seg3 += lst[k].size;
                    nl.push_back(lst[k]);
                }
                int seg2 = lst[j].size;
                nl.push_back(lst[j]);
                int seg1 = 0;
                for (int k = 0; k < j; ++k) {
                    seg1 += lst[k].size;
                    nl.push_back(lst[k]);
                }
                ans.push_back({seg1,seg2,seg3,seg4});
                lst = nl;
                solve(lst, ans);
                return;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<elem> lst(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        lst[i] = {1, a, a};
    }
    vector<vector<int>> ans;
    solve(lst, ans);
    cout << ans.size() << endl;
    for (auto i : ans) {
        int sz = 0;
        for (auto j : i)
            if (j != 0)
                sz += 1;
        cout << sz << ' ';
        for (auto j : i)
            if (j != 0)
                cout << j << ' ';
        cout << endl;
    }

}