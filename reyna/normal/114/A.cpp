#include <iostream>
using namespace std;
int main(){
    int k,l;
    int a = 0;
    cin >> k >> l;
    while(l != 1){
        if(l % k != 0){
            cout << "NO";
            break;
        }else{
            l/=k;
            a++;
        }
    }
    if(l == 1){
        cout << "YES" << endl;
        cout << a-1;
    }
}