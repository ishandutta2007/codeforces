#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int l[1005], r[1005];
        int c = m + 1;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') c = 0;
            else c++;
            l[i] = c;
        }
        c = m + 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1') c = 0;
            else c++;
            r[i] = c;
        }
        for(int i = 0; i < n; i++){
            if(l[i] != r[i] && (l[i] <= m || r[i] <= m)) s[i] = '1';
        }
        cout << s << endl;
    }
}