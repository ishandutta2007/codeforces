#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool f = true;
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                f = false;
                break;
            }
        }
        if(!f){
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for(int j = 0; j < 26; j++){
            char l = char('z' + 1);
            for(int i = 0; i < n; i++){
                if(a[i] == char('a' + j) && b[i] > a[i]){
                    l = min(l, b[i]);
                }
            }
            if(l <= 'z'){
                ans++;
                for(int i = 0; i < n; i++){
                    if(a[i] == char('a' + j) && b[i] > a[i]){
                        a[i] = l;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}