#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int c = 0;
        int d = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') c++;
            else{
                d += min(c, 1);
                c = 0;
            }
        }
        d += min(c, 1);
        cout << min(d, 2) << endl;
    }
}