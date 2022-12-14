#include <iostream>
using namespace std;
int main(){
    long long x;
    long long y;
    cin >> x >> y;
    long long n;
    cin >> n;
    long long k;
    if(n%6==0){
        k = -y+x;
    }else if(n%6==1){
        k = x;
    }else if(n%6==2){
        k = y;
    }else if(n%6==3){
        k = y-x;
    }else if(n%6==4){
        k = -x;
    }else{
        k = -y;
    }
    k %= 1000000007;
    if(k < 0){
        k = 1000000007+k;
    }
    cout << k << endl;
}