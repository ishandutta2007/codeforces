#include <iostream>
#include <algorithm>
using namespace std;
long long arr[300001];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long counter = 0;
    for(long long i = 0; i < n;i++){
        if(i == n-1){
            counter += (i+1)*(long long)arr[i]; 
        }else{
            counter += (i+2)*(long long)arr[i];
        }
    }
    cout << counter << endl;
    return 0;
}