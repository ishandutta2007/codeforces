#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int c[1002], a[1002];
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < m; i++) cin >> a[i];
    int i = 0, j = 0;
    while(i < n && j < m){
        if(c[i] <= a[j]) j++;
        i++;
    }
    cout << j << endl;
}