#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n, k;
        cin >> n >> k;
        int a[200005];
        int o = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 2) o++;
        }
        if(o < k || (o - k) % 2 == 1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(j != k - 1 && a[i] % 2 == 1){
                cout << i + 1 << " ";
                j++;
            }
        }
        cout << n << endl;
    }
}