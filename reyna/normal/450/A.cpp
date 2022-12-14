#include <iostream>
using namespace std;
int n,m;
int Highest= 0;
int numb = 0;
int arr[100];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i]%m != 0){
            arr[i] = arr[i] + m;
        }
        if(Highest <= arr[i]/m){
            numb = i+1;
            Highest = arr[i]/m;
        }
    }
    cout << numb;
}