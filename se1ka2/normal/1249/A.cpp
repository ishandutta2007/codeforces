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
        int a[102];
        bool f = false;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n - 1; i++){
            if(a[i + 1] == a[i] + 1){
                cout << 2 << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << 1 << endl;
    }
}