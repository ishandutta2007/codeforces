#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        if(n % 2 != m % 2) i++;
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i += 2;
            }
        }
        if(j == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}