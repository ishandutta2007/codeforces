//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 123;
int arr[Maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int maxdis = 0;
    for(int i = 1;i < n;i++){
        maxdis = max(maxdis,arr[i]-arr[i-1]);
    }
    int maxremove = 1001;
    for(int i = 2;i < n;i++){
        maxremove = min(maxremove,arr[i]-arr[i-2]);
    }
    cout << max(maxdis,maxremove) << endl;
    return 0;
}