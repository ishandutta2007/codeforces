#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[52][52];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int c = 0, d = 0;
        for(int i = 0; i < n; i++){
            bool f = true;
            for(int j = 0; j < m; j++){
                if(a[i][j]) f = false;
            }
            c += f;
        }
        for(int j = 0; j < m; j++){
            bool f = true;
            for(int i = 0; i < n; i++){
                if(a[i][j]) f = false;
            }
            d += f;
        }
        if(min(c, d) % 2){
            cout << "Ashish" << endl;
        }
        else{
            cout << "Vivek" << endl;
        }
    }
}