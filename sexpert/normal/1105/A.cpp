    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int mxt = -1, mxs = 100000000;
        for(int t = 1; t <= 2000; t++) {
            int s = 0;
            for(int i = 0; i < n; i++) {
                if(abs(t - v[i]) < 2)
                    continue;
                s += abs(t - v[i]) - 1;
            }
            if(s < mxs) {
                mxt = t;
                mxs = s;
            }
        }
        cout << mxt << " " << mxs << endl;
    }