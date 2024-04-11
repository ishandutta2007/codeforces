#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' && t[i] == 'b') a.push_back(i);
        if(s[i] == 'b' && t[i] == 'a') b.push_back(i);
    }
    int l = a.size(), m = b.size();
    if((l + m) % 2){
        cout << -1 << endl;
        return 0;
    }
    if(l % 2) cout << (l + m) / 2 + 1 << endl;
    else cout << (l + m) / 2 << endl;
    for(int i = 0; i + 1 < l; i += 2) cout << a[i] + 1 << " " << a[i + 1] + 1 << endl;
    for(int i = 0; i + 1 < m; i += 2) cout << b[i] + 1 << " " << b[i + 1] + 1 << endl;
    if(l % 2){
        cout << a[l - 1] + 1 << " " << a[l - 1] + 1 << endl;
        cout << a[l - 1] + 1 << " " << b[m - 1] + 1 << endl;
    }
}