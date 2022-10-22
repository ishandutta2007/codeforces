#include <iostream>
using namespace std;
typedef long long ll;

ll a[30][30];

int main()
{
    int n;
    cin >> n;
    for(int i = n - 2; i >= 0; i--){
        for(int j = 1; j < n; j++){
            a[i][j] = 1;
            for(int k = j - 1; k < n; k++) a[i][j] += a[i + 1][k];
            for(int k = i + 2; k < n; k++) a[i][j] += a[k][n - 1];
            for(int k = i + 1; k < n; k++) a[i][j] -= a[k][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << endl;
    int q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        int i = 0, j = 0;
        cout << "1 1" << endl;
        while(i < n - 1 || j < n - 1){
            ll s = 0;
            for(int l = i; l < n; l++) s += a[l][j + 1];
            if(s <= k && j < n - 1) j++;
            else i++;
            cout << i + 1 << " " << j + 1 << endl;
            k -= a[i][j];
        }
        cout << endl;
    }
}