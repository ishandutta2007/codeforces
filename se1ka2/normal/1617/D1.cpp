#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool b[10004];
        int l = -1, r = -1;
        for(int i = 0; i < n - 2; i++){
            cout << "? " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
            cin >> b[i];
            if(i && b[i] != b[i - 1]){
                l = i - 1, r = i + 2;
                break;
            }
        }
        bool ans[10004];
        for(int i = 0; i < n; i++){
            if(i != l && i != r){
                cout << "? " << l + 1 << " " << r + 1 << " " << i + 1 << endl;
                cin >> ans[i];
            }
        }
        int x = -1, y = -1;
        for(int i = 0; i < n; i++){
            if(i != l && i != r && !ans[i]) x = i;
            if(i != l && i != r && ans[i]) y = i;
        }
        cout << "? " << x + 1 << " " << y + 1 << " " << l + 1 << endl;
        cin >> ans[l];
        cout << "? " << x + 1 << " " << y + 1 << " " << r + 1 << endl;
        cin >> ans[r];
        int k = 0;
        for(int i = 0; i < n; i++) k += !ans[i];
        cout << "! " << k;
        for(int i = 0; i < n; i++){
            if(!ans[i]) cout << " " << i + 1;
        }
        cout << endl;
    }
}