#include<iostream>
using namespace std;

long long n, s, c, a[4];

int main(){
    a[3]=1;
    for(cin >> n; n; n--){
        for(s=c=0; c<4; c++)
            s+=a[c];
        for(c=0; c<4; c++)
            a[c]=(s-a[c])%1000000007;
    }
    cout << a[3] << endl;
}