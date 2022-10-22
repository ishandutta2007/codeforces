#include <iostream>
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
        for(int i = 0; i < n; i++) cout << s[n - 1];
        cout << endl;
    }
}