#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,a,x=0;
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> a;
        x+=a*i*4;
    }
    cout << x << endl;
}