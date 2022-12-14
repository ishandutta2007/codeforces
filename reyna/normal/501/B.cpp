//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e3 + 20;
string arr[Maxn];
string f[Maxn];
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n;i++){
        string S,P;
        cin >> S >> P;
        bool flag = 0;
        int in = -1;
        for(int j = 0; j < cnt;j++){
            if(S == arr[j]){
                flag = 1;
                in = j;
            }
            if(arr[j] == P){
                flag = 0;
                break;
            }
        }
        if(flag){
            arr[in] = P;
        }else if(in == -1){
            arr[cnt] = P;
            f[cnt++] = S;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt;i++){
        cout << f[i] << ' ' << arr[i] << endl;
    }
    return 0;
}