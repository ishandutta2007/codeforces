#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin >> a;
    int counter = 1;
    for(int i = 1;i<a.length();i++){
        if(a[i] == a[i-1]){
            counter++;
        }else{
            counter = 1;
        }
        if(counter >= 7){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}