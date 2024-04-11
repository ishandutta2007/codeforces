#include <iostream>
#include <string>
using namespace std;
string a;
int arr[100000];
int ans[100000];
int main(){
    cin >> a;
    int n;
    cin >> n;
    arr[0] = 0;
    for(int i = 1; i < a.length();i++){
        if(a[i] == a[i-1]){
            arr[i] = arr[i-1]+1;
        }else{
            arr[i] = arr[i-1];
        }
    }
    for(int i = 0; i < n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        ans[i] = arr[b]-arr[a];
    }
    for(int i = 0; i < n;i++){
        cout << ans[i] << endl;
    }
}