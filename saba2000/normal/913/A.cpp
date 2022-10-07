#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m;
    cin >> n>>m;
    if (n >= 30) cout << m << endl;
    else cout << m% ((1<<n)) << endl;
}