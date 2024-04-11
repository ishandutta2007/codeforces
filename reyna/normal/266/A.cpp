#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a;
    int counter = 0;
    cin >> a;
    for(int i = 1 ; i < a.length();i++){
        if(a[i] == a[i-1]){
            counter++;
        }
    }
    cout << counter;
}