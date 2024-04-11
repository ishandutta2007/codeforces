//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 55;
int arr[Maxn];
int main(){
    long long n,m;
    cin >> n >> m;
    --m;
    int l = 0,r = n-1;
    for(int i = n-1; i >= 1;--i){
        if(((long long)1 << (i-1)) & m){
            arr[r--] = n-i;
        }else{
            arr[l++] = n-i;
        }
    }
    arr[l] = n;
    for(int i = 0; i < n;i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}