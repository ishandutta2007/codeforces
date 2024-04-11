#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int j = 0; j <100000;j++){
        for(int i = 0; i < n;i++){
            if(m-i-1 < 0){
                cout << m;
                return 0;
            }
            m -= i+1;
        }
    }

}