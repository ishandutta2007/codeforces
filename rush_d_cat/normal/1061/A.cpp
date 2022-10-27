#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n,s;
int main() {
    cin>>n>>s;
    if(s%n == 0)
        cout << s/n << endl;
    else
        cout << s/n+1 << endl;
}