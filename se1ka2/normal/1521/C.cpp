#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = n - 1;
        for(int i = 0; i < n - 1; i += 2){
            cout << "? 2 " << i + 1 << " " << i + 2 << " " << 1 << endl;
            int c;
            cin >> c;
            if(c == 1){
                l = i;
                break;
            }
            if(c == 2){
                cout << "? 2 " << i + 2 << " " << i + 1 << " " << 1 << endl;
                int d;
                cin >> d;
                if(d == 1){
                    l = i + 1;
                    break;
                }
            }
        }
        int p[10005];
        p[l] = 1;
        for(int i = 0; i < n; i++){
            if(i == l) continue;
            cout << "? 1 " << l + 1 << " " << i + 1 << " " << n - 1 << endl;
            int c;
            cin >> c;
            p[i] = c;
        }
        cout << "! ";
        for(int i = 0; i < n; i++) cout << p[i] << " ";
        cout << endl;
    }
}