// In the name of God
#include <iostream>
#include<cmath>
using namespace std;
int arr1[200000];
int arr2[200000];
int main(){
    int n;
    cin >> n;
    int ptr1 = 0;
    int ptr2 = 0;
    long long first = 0;
    int last = 1;
    long long second = 0;
    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        if(a < 0){
            arr2[ptr2++] = abs(a);
            last = 2;
            second += abs(a);
        }
        else{
            arr1[ptr1++] = abs(a);
            last = 1;
            first += abs(a);
        }
    }
    if(first < second){
        cout << "second" << endl;
        return 0;
    }
    if(second < first){
        cout << "first" << endl;
        return 0;
    }
    for(int i = 0; i < max(ptr1,ptr2);i++){
        if(arr1[i] < arr2[i]){
            cout << "second" << endl;
            return 0;
        }
        if(arr2[i] < arr1[i]){
            cout << "first" << endl;
            return 0;
        }
    }
    if(last == 2){
        cout << "second" << endl;
        return 0;
    }
    cout << "first" << endl;
    return 0;
}