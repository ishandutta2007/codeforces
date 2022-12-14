#include <iostream>
using namespace std;
int main(){
    int n,s;
    cin >> n >> s;
    int max1 = -1;
    for(int i = 0; i < n;i++){
        int a;
        int b;
        cin >> a >> b;
        if(a <= s && b == 0){
            max1 = max(0,max1);
        }
        else if(a < s && b != 0){
            max1 = max(100-b,max1);
        }
    }
    cout << max1 << endl;
    return 0;
}