#include <iostream>
using namespace std;
int arr[100000];
int main(){
    int n;
    cin >> n;
    int counter = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        counter+= arr[i];
    }
    int baghibar2 = counter%2;
    counter = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]%2==baghibar2){
            counter++;
        }
    }
    cout << counter;
}