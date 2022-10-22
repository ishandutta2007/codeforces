#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool> > a(n, vector<bool>(m, false));
    for(int i = 0; i < k; i++){
        int a1, a2;
        cin >> a1 >> a2;
        a1--;
        a2--;
        a[a1][a2] = true;

        bool flag = false;
        if(a1 > 0 && a2 > 0)
            if(a[a1 - 1][a2 - 1] && a[a1 - 1][a2] && a[a1][a2 - 1])flag = true;

        if(a1 > 0 && a2 < m - 1)
            if(a[a1 - 1][a2 + 1] && a[a1 - 1][a2] && a[a1][a2 + 1])flag = true;

        if(a1 < n - 1 && a2 < m - 1)
            if(a[a1 + 1][a2 + 1] && a[a1 + 1][a2] && a[a1][a2 + 1])flag = true;

        if(a1 < n - 1 && a2 > 0)
            if(a[a1 + 1][a2] && a[a1 + 1][a2 - 1] && a[a1][a2 - 1])flag = true;

        if(flag){
            cout << i + 1;
            return 0;
        }

    }

    cout << 0;
}