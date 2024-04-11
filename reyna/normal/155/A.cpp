#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a;
    cin >> a;
    int max=a,min=a;
    int counter = 0;
    for(int i = 1; i < n;i++){
        int a;
        cin >> a;
        if(a > max){
            max = a;
            counter++;
        }else if(a < min){
            min = a;
            counter++;
        }
    }
    cout << counter;
}