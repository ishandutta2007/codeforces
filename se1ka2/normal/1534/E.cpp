#include <iostream>
using namespace std;

int query(int k, int *b){
    cout << "?";
    for(int i = 0; i < k; i++) cout << " " << b[i] + 1;
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void normal(int k, int e, int c){
    int ans = 0;
    int b[502];
    for(int i = 0; i < e / 2; i++) b[i] = i;
    for(int i = e / 2; i < k; i++) b[i] = i + e / 2;
    ans ^= query(k, b);
    for(int i = 0; i < k; i++) b[i] = i + e / 2;
    ans ^= query(k, b);
    for(int t = 0; t < c; t++){
        for(int i = 0; i < k; i++) b[i] = i + e + k * t;
        ans ^= query(k, b);
    }
    cout << "! " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int b[502];
    if(n % k == 0){
        int ans = 0;
        for(int d = 0; d < n / k; d++){
            for(int i = 0; i < k; i++) b[i] = d * k + i;
            ans ^= query(k, b);
        }
        cout << "! " << ans << endl;
        return 0;
    }
    int e;
    if(k % 2 == 0){
        if(n % 2){
            cout << -1 << endl;
            return 0;
        }
        if(k * 2 > n){
            e = n - k;
            normal(k, e, 1);
        }
        else{
            e = n % k + k;
            normal(k, e, (n - e) / k);
        }
    }
    else{
        if((n % k) % 2 == 0){
            e = n % k;
            normal(k, e, n / k);
        }
        else{
            if(k * 2 < n){
                e = n % k + k;
                normal(k, e, n / k - 1);
            }
            else{
                int r = 0;
                int ans = 0;
                int e = (n - k) * 2;
                while(true){
                    if(n > r + e){
                        for(int i = 0; i < e / 2; i++) b[i] = (r + i) % n;
                        for(int i = e / 2; i < k; i++) b[i] = (r + i + e / 2) % n;
                        ans ^= query(k, b);
                        for(int i = 0; i < k; i++) b[i] = (r + i + e / 2) % n;
                        ans ^= query(k, b);
                        r += e;
                    }
                    else{
                        e = n - r;
                        for(int i = 0; i < e / 2; i++) b[i] = (r + i) % n;
                        for(int i = e / 2; i < k; i++) b[i] = (r + i + e / 2) % n;
                        ans ^= query(k, b);
                        for(int i = 0; i < k; i++) b[i] = (r + i + e / 2) % n;
                        ans ^= query(k, b);
                        r += e;
                        break;
                    }
                }
                cout << "! " << ans << endl;
            }
        }
    }
}