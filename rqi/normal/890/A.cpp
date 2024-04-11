#include <iostream>

using namespace std;
int main() {
    int a[6];
    bool flag = false;
    for(int i = 0; i < 6; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 0; i < 6; i++){
        sum+=a[i];
    }
    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            for(int k = j+1; k < 6; k++){
                if((a[i] + a[j] + a[k])*2 == sum){
                    flag = true;
                }
            }
        }
    }
    if(flag == true){
        cout << "YES";
    }
    else cout << "NO";
}