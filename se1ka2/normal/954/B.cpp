#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for(int i = n / 2; i > 0; i--){
        int j;
        for(j = i; j < i * 2; j++){
            if(s[j] != s[j - i]) break;
        }
        if(j == i * 2){
            cout << n - i + 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
}