#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string a[2004];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        bool f = true;
        for(int j = 0; j < m; j++){
            if(a[i][j] == '1'){
                int g = false;
                for(int k = 0; k < n; k++){
                    if(k == i) continue;
                    if(a[k][j] == '1') g = true;
                }
                f &= g;
            }
        }
        if(f){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}