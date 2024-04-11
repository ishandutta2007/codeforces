#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n - 1; i++){
        if(s[i] > s[i + 1]){
            for(int j = 0; j < i; j++) cout << s[j];
            for(int j = i + 1; j < n; j++) cout << s[j];
            cout << endl;
            return 0;
        }
    }
    for(int j = 0; j < n - 1; j++) cout << s[j];
    cout << endl;
}