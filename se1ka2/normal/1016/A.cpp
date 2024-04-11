#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int s = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cout << (a + s) / m << " ";
        s = (s + a) % m;
    }
    cout << endl;
}