#include <iostream>
#include <string>
using namespace std;
int arr[1000];
int main(){
    string a;
    cin >> a;
    int a1=0,a2=0,a3=0;
    for(int i = 0; 2*i < a.length();i++){
    //  cout << a[2*i];
        if(a[2*i] == '1'){
            a1++;
        }else if(a[2*i] == '2'){
            a2++;
        }else if(a[2*i] == '3'){
            a3++;
        }
    }
    //cout << a1 << " " << a2 << " " << a3;
    for(int i = 0;i<a.length();i++){
        if(i%2 == 0 && a1 != 0){
            cout << 1;
            a1--;
        }else if(i%2 == 0 && a2 != 0){
            cout << 2;
            a2--;
        }else if(i%2 == 0 && a3 != 0){
            cout << 3;
            a3--;
        }else if(i%2 == 1){
            cout << '+';
        }
    }
}