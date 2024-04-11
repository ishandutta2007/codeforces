#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[500];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++){
        int l = s[i].size();
        int t = 0, z = 0, e = 0;
        for(int j = 0; j < l; j++){
            if(s[i][j] == '0') z++;
            if((s[i][j] - '0') % 2 == 0) e++;
            t += (s[i][j] - '0');
        }
        if(t % 3) cout << "cyan" << endl;
        else if(z == 0 || (z == 1 && e == 1)) cout << "cyan" << endl;
        else cout << "red" << endl;
    }
}