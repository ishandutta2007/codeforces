    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int m = *max_element(v.begin(), v.end());
        int ct = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == m)
                ct++;
            else
                mx = max(mx, ct), ct = 0;
        }
        mx = max(mx, ct);
        cout << mx << endl;
    }