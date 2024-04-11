#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[302][302];
        bool f = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                int c = 2;
                if(i > 0 && i < n - 1) c++;
                if(j > 0 && j < m - 1) c++;
                if(a[i][j] > c) f = false;
            }
        }
        if(!f){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int c = 2;
                if(i > 0 && i < n - 1) c++;
                if(j > 0 && j < m - 1) c++;
                cout << c << " ";
            }
            cout << endl;
        }
    }
}