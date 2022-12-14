#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int counter = 0;
    int counter2 = 0;
    for(int i = 0; i < n;i++){
        int k;
        cin >> k;
        counter+= k;
    }
    for(int i = 0; i < 5;i++){
        if((counter+i+1)%(n+1) != 1){
            counter2++;
        }
    }
    cout << counter2;
}