#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int d[12];
    d[1] = 1;
    for(int i = 2; i < 10; i++) d[i] = d[i - 1] * 10;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b) cout << d[a] + d[c] << " " << d[b] << endl;
        else cout << d[a] << " " << d[b] + d[c] << endl;
    }
}