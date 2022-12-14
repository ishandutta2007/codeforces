#include <iostream>
using namespace std;
int arr[100];
int c;
int counter;
int counter2;
int a1;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> arr[i];
        counter+=arr[i];
    }
    for(int i = 0; i< n; i++)
        for(int j = i; j>0; j--)
            if(arr[j] < arr[j-1]){
                c = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = c;
            }
    for(int i = n-1; i >= 0; i--){
        if(counter2 + arr[i] > counter - arr[i]){
            cout << a1 + 1;
            return 0;
        }else{
            counter2 += arr[i];
            counter -= arr[i];
            a1++;
        }
    }
}