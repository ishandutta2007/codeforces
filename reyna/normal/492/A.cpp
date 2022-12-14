// In the name of God
#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long tmp = 0;
    long long level = 0;
    while(tmp <= n){
        level++;
        tmp+=(level*(level+1))/2;
    }
    level--;
    cout << level << endl;
    return 0;
    
}