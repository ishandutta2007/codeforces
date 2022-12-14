#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == 'H' || a[i] == 'Q' || a[i] == '9'){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}