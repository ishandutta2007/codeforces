    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        if(x > y) {
            cout << n << endl;
            return 0;
        }
        int ct = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] <= x)
                ct++;
        }
        cout << (ct + 1)/2 << endl;
        return 0;
    }