#include <iostream>
using namespace std;
int arr[101];
bool a[101];
int main(){
    int n,d;
    cin >> n >> d;
    for(int i = 0;i < n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    int counter = 0;
    if(n < m){
        counter -= (m-n)*d;
        m = n;
    }
    int min1 = 101;
    int lastandis = 0;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            if(arr[j] < min1 && a[j] == false){
                min1 = arr[j];
                lastandis = j;
            }
        }
        a[lastandis] = true;
        counter += arr[lastandis];
        min1 = 101;
    }
    cout << counter << endl;
    return 0;
}