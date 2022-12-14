#include <iostream>
using namespace std;
bool arr[10];
int main(){
    int n;
    cin >> n;
    int a = n;
    while(a++){
        int j = a;
        for(int i = 0; i < 4;i++){
            arr[j%10] = true;
            j/=10;
        }
        int counter = 0;
        for(int i = 0; i < 10;i++){
            if(arr[i] == true){
                counter++;
            }
        }
        for(int i = 0; i<10;i++){
            arr[i] = false;
        }
        if(counter == 4){
            cout << a;
            break;
        }
    }
}