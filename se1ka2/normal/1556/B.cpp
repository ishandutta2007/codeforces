#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        int s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] %= 2;
            s += a[i];
        }
        if(abs(s * 2 - n) >= 2){
            cout << -1 << endl;
            continue;
        }
        ll d[2]{0};
        for(int c = 0; c < 2; c++){
            int j = 0;
            for(int i = 0; i < n; i++){
                if(a[i]){
                    d[c] += abs(i - (j * 2 + c));
                    j++;
                }
            }
        }
        if(n % 2){
            if(s * 2 > n) cout << d[0] << endl;
            else cout << d[1] << endl;
        }
        else cout << min(d[0], d[1]) << endl;
    }
}