#include <iostream>
using namespace std;
int main(){
    int a1=0,a2=0,a4=0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 25){
            a1++;
        }else if(a == 50 && a1 > 0){
            a2++;
            a1--;
        }else if(a == 100 && a1 > 0 && a2 > 0){
            a4++;
            a1--;
            a2--;
        }else if(a == 100 && a1 > 2){
            a4++;
            a1 = a1 - 3;
        }else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}