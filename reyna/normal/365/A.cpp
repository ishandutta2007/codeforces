#include <iostream>
using namespace std;
bool arr[100][10];
int main(){
    int n;
    int k;
    cin >> n >> k;
    int counter = n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        while(a != 0){
            arr[i][a%10] = true;
            a /= 10;
        }
        for(int j = 0; j <= k; j++){
            if(arr[i][j] == false){
                counter--;
                break;
            }
        }
    }
    cout << counter << endl;
    return 0;
}