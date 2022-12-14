#include <iostream>
using namespace std;
int a[3];
int suma;
int sumb;
int b[3];
int main(){
    int n;
    for(int i = 0; i < 3;i++){
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 0; i < 3;i++){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma%5!=0){
        suma += 5;
    }
    if(sumb%10!=0){
        sumb += 10;
    }
    cin >> n;
    if(suma/5 + sumb/10 <= n){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}