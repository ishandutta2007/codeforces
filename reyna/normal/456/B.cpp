#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    int b = int(a[a.length()-1])-'0';
    if(a.length() != 1){
        b += (int(a[a.length()-2])-'0')*10;
    }
    if(b%4==0){
        cout << 4;
    }else{
        cout << 0;
    }
    cout << endl;
    return 0;
}