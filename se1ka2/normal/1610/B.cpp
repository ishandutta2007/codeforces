#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        bool f = true;
        for(int i = 0; i < n; i++){
            if(a[i] != a[n - i - 1]){
                f = false;
                int x = a[i];
                int y = a[n - i - 1];
                int b[200005];
                int m = 0;
                for(int j = 0; j < n; j++){
                    if(a[j] != x) b[m++] = a[j];
                }
                bool g = true;
                for(int j = 0; j < m; j++){
                    if(b[j] != b[m - j - 1]){
                        g = false;
                        break;
                    }
                }
                if(g){
                    f = true;
                    break;
                }
                m = 0;
                for(int j = 0; j < n; j++){
                    if(a[j] != y) b[m++] = a[j];
                }
                g = true;
                for(int j = 0; j < m; j++){
                    if(b[j] != b[m - j - 1]){
                        g = false;
                        break;
                    }
                }
                if(g) f = true;
                break;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}