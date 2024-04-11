#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    if(int(a[0]) >= 'a'){
        a[0] = (char)(int(a[0])-32);
    }
    cout << a;
}