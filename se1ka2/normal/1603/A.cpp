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
        bool g = true;
        for(int i = 0; i < n; i++){
            bool f = false;
            for(int j = 0; j <= i; j++){
                if(a[i] % (j + 2)){
                    f = true;
                    break;
                }
            }
            if(!f){
                g = false;
                break;
            }
        }
        if(g) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}