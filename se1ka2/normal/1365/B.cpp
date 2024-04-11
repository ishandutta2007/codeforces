#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[503], b[503];
        bool f = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0 && a[i] < a[i - 1]) f = false;
        }
        bool g = false;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(i > 0 && b[i] != b[i - 1]) g = true;
        }
        if(f || g) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}