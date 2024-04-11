#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    char les = 'z';
    for(int i = 0; i < n; i++){
        if(s[i] <= les){
            cout << "Mike" << endl;
            les = s[i];
        }
        else cout << "Ann" << endl;
    }
}