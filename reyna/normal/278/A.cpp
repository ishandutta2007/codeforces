#include <iostream>
using namespace std;
int arr[1000];
int main(){
    int n;
    cin >> n;
    int sum = 0;
    int counter = 0;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    int t,s;
    cin >> t >> s;
    if(t == s){
        cout << 0;
        return 0;
    }
    if(t > s){
        int c = t;
        t = s;
        s = c;
    }
    for(int i = t-1; i < s-1; i++){
        counter += arr[i];
    }
    if(sum-counter < counter){
        cout << sum-counter;
    }else{
        cout << counter;
    }
    return 0;
}