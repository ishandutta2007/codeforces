#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[102], b[102];
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int c[102];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            c[i] = 1;
            ans++;
        }
        else c[i] = 0;
    }
    for(int i = 0; i < 130; i++){
        int now = 0;
        for(int j = 0; j < n; j++){
            if(i - b[j] >= 0 && (i - b[j]) % a[j] == 0){
                c[j] = 1 - c[j];
            }
        }
        for(int j = 0; j < n; j++) if(c[j] == 1) now++;
        ans = max(ans, now);
    }
    cout << ans << endl;
}