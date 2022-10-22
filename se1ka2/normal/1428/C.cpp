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
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'A') a++;
            else if(a) a--;
            else if(b) b--;
            else b++;
        }
        cout << a + b << endl;
    }
}