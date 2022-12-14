#include <iostream>
using namespace std;
int arr[101];
int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    int max = 0;
    int maxid = 0;
    int min = 101;
    int minid = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(max < arr[i]){
            max = arr[i];
            maxid = i;
        }
        if(min >= arr[i]){
            min = arr[i];
            minid = i;
        }
    }
    if(maxid < minid){
        cout << n-1-minid + maxid;
    }else{
        cout << n-2-minid+maxid;
    }
}