#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a1=0,a2=0,a3=0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(i%3 == 0){
            a1 += a;
        }else if(i%3 == 1){
            a2 += a;
        }else if(i%3 == 2){
            a3 += a;
        }
    }
    if(a1 > a2 && a1 > a3){
        cout << "chest";
    }else if(a3 > a2 && a3 > a1){
        cout << "back";
    }else{
        cout << "biceps";
    }
}