#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        for(int i = 0; i < n; ++i){
            if(a[i] < 0)
                a[i] = -a[i];

            if(i & 1)
                a[i] = -a[i];
        }

        for(int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << "\n";
    }
}