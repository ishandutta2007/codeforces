#include <iostream>
using namespace std;
int arr[100000];
int numbers[100000];
int l[100000];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> numbers[i];
        numbers[i]--;
        arr[numbers[i]]++;
    }
    int counter = 0;
    for(int i = 0; i < 100000;i++){
        if(arr[i] != 0){
            counter++;
        }
    }
    l[0] = counter;
    for(int i = 1; i < n;i++){
        arr[numbers[i-1]]--;
        if(arr[numbers[i-1]] == 0){
            l[i] = l[i-1]-1;
        }else{
            l[i] = l[i-1];
        }
    }
    for(int i = 0; i < m;i++){
        int a;
        cin >> a;
        a--;
        cout << l[a] << endl;
    }
    return 0;
}