#include <iostream>

using namespace std;

int main()
{
    long long int n,ans=0;
    cin >> n;
    while(n>=100){
        n-=100;
        ans++;
    }
    while(n>=20){
        n-=20;
        ans++;
    }
    while(n>=10){
        n-=10;
        ans++;
    }
    while(n>=5){
        n-=5;
        ans++;
    }
    ans+=n;
    cout << ans << endl;
    return 0;
}