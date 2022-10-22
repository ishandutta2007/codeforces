#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    bool b[10005]{0};
    for(int i = 1; i <= 100; i++) b[i * i] = true;
    while(t--){
        int n;
        cin >> n;
        bool f = false;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(!b[a]) f = true;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}