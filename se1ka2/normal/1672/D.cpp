#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005], b[200005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            b[i]--;
        }
        int c[200005];
        for(int i = 0; i < n; i++) c[i] = 0;
        int j = 0;
        bool f = true;
        for(int i = 0; i < n; i++){
            while(true){
                if(i > 0 && b[i] == b[i - 1] && c[b[i]]){
                    c[b[i]]--;
                    break;
                }
                if(j == n){
                    f = false;
                    break;
                }
                if(b[i] == a[j]){
                    j++;
                    break;
                }
                c[a[j]]++;
                j++;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}