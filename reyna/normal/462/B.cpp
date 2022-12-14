#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[26];
int main(){
    int n,k;
    cin >> n >> k;
    string a;
    cin >> a;
    for(int i = 0; i < n;i++){
        arr[a[i]-'A']++;
    }
    sort(arr,arr+26);
    int b = 25;
    long long counter = 0;
    while(k != 0){
        if(arr[b] <= k){
            counter+=(long long)arr[b]*arr[b];
            k-=arr[b];
        }else{
            counter+=(long long)k*k;
            break;
        }
        b--;
    }
    cout << counter << endl;
    return 0;
}