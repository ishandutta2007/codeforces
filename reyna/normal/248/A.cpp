//In the name of God
#include <iostream>
using namespace std;
int main(){
    int a = 0,b = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int l,r;
        cin >> l >> r;
        a += l,b += r;
    }
    cout << min(a,n-a) + min(b,n-b) << endl;
    return 0;
}