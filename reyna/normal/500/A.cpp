//In the name of God
#include <iostream>
using namespace std;
int main(){
    int n,dest;
    cin >> n >> dest;
    dest--;
    int now = 0;
    for(int i = 0; i < n-1;i++){
        int tel;
        cin >> tel;
        if(now == i)
            now += tel;
        if(dest == now){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}