#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int max1 = 0;
    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        max1 = max(a,max1);
    }
    cout << max1 << endl;
    return 0;
}