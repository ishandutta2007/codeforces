#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 6;
int a[6] = {4, 8, 15, 16, 23, 42};
vector<int> ans;
set<int> s[6];

void solve3(int i) {
    int x, y;
    cout << "? " << i << " " << (i+1) << endl;
    cin >> x;
    cout << "? " << i << " " << (i+2) << endl;
    cin >> y;

    for (int i = 0; i < 6; i++)
        if (s[i].count(x) && s[i].count(y)) {
            ans.push_back(a[i]);
            ans.push_back(x/a[i]);
            ans.push_back(y/a[i]);
        }
}

int main(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j) {
            s[i].insert(a[i]*a[j]);
        }
    }
    solve3(1); solve3(4);
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}