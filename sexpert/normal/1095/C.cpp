    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n, k;
        cin >> n >> k;
        if(k < __builtin_popcount(n) || k > n) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        int s = __builtin_popcount(n);
        int bits[32];
        memset(bits, 0, sizeof bits);
        for(int i = 0; i < 32; i++) {
            if(n & (1 << i))
                bits[i]++;
        }
        while(s < k) {
            for(int i = 31; i >= 1; i--) {
                if(bits[i] > 0) {
                    bits[i]--;
                    bits[i - 1] += 2;
                    break;
                }
            }
            s++;
        }
        for(int i = 0; i < 32; i++) {
            while(bits[i] > 0) {
                bits[i]--;
                cout << (1 << i) << " ";
            }
        }
        cout << endl;
    }