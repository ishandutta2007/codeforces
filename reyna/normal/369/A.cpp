#include <iostream>
using namespace std;
int main(){
    int n,m,k;
    int counter = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        if(a == 1 && m != 0){
            m--;
        }else if(a == 1 && m == 0){
            counter++;
        }else if(a == 2 && k != 0){
            k--;
        }else if(a == 2 && k == 0 && m != 0){
            m--;
        }else if(a == 2 && k == 0 && m == 0){
            counter++;
        }
    }
    cout << counter;
}