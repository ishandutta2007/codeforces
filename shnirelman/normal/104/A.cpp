#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 1000000;

int main(){
    int n;
    cin >> n;

    n -= 10;

    if(n <= 0)cout << 0;
    else if(n < 10 || n == 11)cout << 4;
    else if(n == 10)cout << 15;
    else cout << 0;
}