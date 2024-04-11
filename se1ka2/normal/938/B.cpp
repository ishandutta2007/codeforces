#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int l = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        l = max(l, min(a - 1, 1000000 - a));
    }
    cout << l << endl;
}