#include <iostream>
using namespace std;
int main(){
    long long n,m;
    cin >> n >> m;
    if((n/2+(n%2))>=m)
        cout << 2*m-1;
    if((n/2+(n%2))<m)
        cout << 2*(m-(n/2+(n%2)));
}