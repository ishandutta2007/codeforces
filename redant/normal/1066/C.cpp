#include <iostream>
#include <map>

using namespace std;

int main(){
    int q; cin >> q;
    int l = 0, r = 0;
    map<int, int> ind;
    while (q--) {
        int id;
        char op;
        cin >> op >> id;
        if (op == 'L') {
            ind[id] = --l;
        } else if (op == 'R') {
            ind[id] = r++;
        } else {
            int k = ind[id];
            cout << min(k - l, r - k - 1) << endl;
        }
    }

    return 0;
}