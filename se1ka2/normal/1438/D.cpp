#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(!(n % 2)){
        int x = 0;
        for(int i = 0; i < n; i++) x ^= a[i];
        if(x){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    int i;
    if(n % 2) cout << n - 2 << endl;
    else cout << n - 3 << endl;
    for(i = 0; i < n - 4; i += 2){
        cout << i + 1 << " " << i + 2 << " " << i + 3 << endl;
    }
    for(; i >= 0; i -= 2){
        cout << i + 1 << " " << i + 2 << " " << i + 3 << endl;
    }
}