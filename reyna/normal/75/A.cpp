#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int c = 0;
    int d = 0;
    long long e = a+b;
    long long f = 0;
    int counter = 1;
    while(e != 0){
        if(e%10!=0){
            f+=counter*(e%10);
            counter*=10;
        }
        e/=10;
    }
    counter = 1;
    while(a != 0){
        if(a%10!=0){
            c+= counter*(a%10);
            counter*=10;
        }
        a/=10;
    }
    counter = 1;
    while(b != 0){
        if(b%10!=0){
            d+= counter*(b%10);
            counter*=10;
        }
        b/=10;
    }
    if(c+d==f){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}