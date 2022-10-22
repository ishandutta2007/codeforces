#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int a[200005];
    int c = 0;
    for(int i = 0; i < n; i++){
        a[c * n + i] = i * 2;
        c = 1 - c;
        a[c * n + i] = i * 2 + 1;
    }
    for(int i = 0; i < n * 2; i++) cout << a[i] + 1 << " ";
    cout << endl;
}