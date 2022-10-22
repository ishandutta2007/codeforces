#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        int one = 0;
        bool odd = false;
        string s[52];
        for(int i = 0; i < n; i++){
            cin >> s[i];
            if((int)s[i].size() % 2 == 1) odd = true;
            for(int j = 0; j < (int)s[i].size(); j++){
                if(s[i][j] == '1') one++;
            }
        }
        if(odd) cout << n << endl;
        else if(one % 2 == 0) cout << n << endl;
        else cout << n - 1 << endl;
    }
}