#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    int counter = 0;
    for(int i = 0; i < a.length();i++){
        if(a[i] == 'h' && counter == 0){
            counter++;
        }else if(a[i] == 'e' && counter == 1){
            counter++;
        }else if(a[i] == 'l' && counter == 2){
            counter++;
        }else if(a[i] == 'l' && counter == 3){
            counter++;
        }else if(a[i] == 'o' && counter == 4){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}