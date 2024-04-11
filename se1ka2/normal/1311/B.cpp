#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, m;
        cin >> n >> m;
        int a[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        int p[102];
        bool b[102]{0};
        for(int i = 0; i < m; i++){
            cin >> p[i];
            b[p[i]] = true;
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            int l = i;
            for(int j = i; j < n; j++){
                if(a[j] < a[l]) l = j;
            }
            while(l > i){
                if(!b[l]){
                    f = false;
                }
                swap(a[l], a[l - 1]);
                l--;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}