#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;



int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n * 2);
    for(int i = 0; i < n * 2; i++)
        cin >> a[i];

    vector<bool> used(n * 2, false);

    vector<int> b(n * 2, -1);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        b[x] = y;
        b[y] = x;
    }

    int t;
    cin >> t;

    int lst = -1;
    if(t == 2) {
        int x;
        cin >> x;

        x--;

        used[x] = true;
        lst = x;
    }

    for(int i = 0; i < n; i++) {
        if(lst != -1 && b[lst] != -1 && !used[b[lst]]) {
            cout << b[lst] + 1 << endl;
            used[b[lst]] = true;
        } else {
            int bst = -1;
            for(int j = 0; j < n * 2; j++) if(!used[j]) {
//                if(bst == -1 || (b[bst] == -1 && a[bst] < a[j]))
//                    bst = j;
                if(b[j] != -1) {
//                    cout << j << ' ' << a[j] << ' '<< a[b[j]] << ' ' << b[bst] << endl;
                    if((bst == -1 || b[bst] == -1) && a[j] >= a[b[j]]){
                        bst = j;
//                        cout << j << ' ' << a[j] << ' '<< a[b[j]] << endl;
                    }

                } else if(bst == -1 || (b[bst] == -1 && a[bst] < a[j]))
                    bst = j;
            }

            cout << bst + 1 << endl;
            used[bst] = true;
        }
        if(i < n - 1) {
            cin >> lst;
            lst--;
            used[lst] = true;
        }

    }

}