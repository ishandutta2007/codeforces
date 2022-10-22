#include <iostream>

using namespace std;

int fact(int n){
    if(n == 1)
        return 1;
    return fact(n - 1) * n;
}

int main()
{
    int a ,b;
    cin >> a >> b;
    if(a > b)
        a = b;
    cout << fact(a) << endl;
}