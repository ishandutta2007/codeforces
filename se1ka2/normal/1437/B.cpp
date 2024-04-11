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
        string s;
        cin >> s;
        int z = 0, o = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == '0' && s[i - 1] == '0') z++;
            if(s[i] == '1' && s[i - 1] == '1') o++;
        }
        cout << max(z, o) << endl;
    }
}