#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        int a[502];
        for(int i = 0; i < n * 4; i++) cin >> a[i];
        sort(a, a + n * 4);
        bool f = true;
        int s = a[0] * a[n * 4 - 1];
        for(int i = 0; i < n; i++){
            if(a[i * 2] != a[i * 2 + 1] || a[n * 4 - 1 - i * 2] != a[n * 4 - 2 - i * 2]){
                cout << "NO" << endl;
                f = false;
                break;
            }
            if(a[i * 2] * a[n * 4 - 1 - i * 2] != s){
                cout << "NO" << endl;
                f = false;
                break;
            }
        }
        if(f) cout << "YES" << endl;
    }
}