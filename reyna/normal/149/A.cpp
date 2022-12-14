#include <iostream>
using namespace std;
int arr[12];
int main(){
    int k;
    int c;
    cin >> k;
    int counter = 0;
    int numb = 0;
    for(int i = 0; i< 12; i++)
        cin >> arr[i];
    for(int i = 0; i< 12; i++)
        for(int j = i; j>0; j--)
            if(arr[j] > arr[j-1]){
                c = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = c;
            }
    if(k == 0){
        cout << 0;
        return 0;
    }
    for(int i = 0; i<12; i++){
        counter+=arr[i];
        numb++;
        if(counter >= k){
            break;
        }
    }
    if(counter < k){
        cout << -1;
        return 0;
    }
    cout << numb;
}