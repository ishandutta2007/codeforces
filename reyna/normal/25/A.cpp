#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int counter = 0;
    int numb = 0;
    int numb1 = 0;
    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        if(a % 2 == 1){
            counter++;
            numb = i;
        }else{
            numb1 = i;
        }
    }
    if(counter == 1){
        cout << numb+1;
    }else{
        cout << numb1+1;
    }
}