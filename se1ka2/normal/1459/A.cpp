#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] > t[i]) a++;
            if(s[i] < t[i]) b++;
        }
        if(a > b) cout << "RED" << endl;
        else if(a < b) cout << "BLUE" << endl;
        else cout << "EQUAL" << endl;
    }
}