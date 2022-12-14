#include <iostream>
using namespace std;
int arr[10000][2];
int main(){
    int s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    for(int i = 0; i< n; i++)
        for(int j = i; j>0; j--)
            if(arr[j][0] < arr[j-1][0]){
                swap(arr[j][0],arr[j-1][0]);
                swap(arr[j][1],arr[j-1][1]);
            }
    for(int i = 0;i<n;i++){
        if(arr[i][0] < s){
            s += arr[i][1];
        }else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}