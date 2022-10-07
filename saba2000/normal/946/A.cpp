#include<bits/stdc++.h>
using namespace std;
int a[1090];
main()
{
    int n;
    cin >> n;
    int s=0;
    for (int i = 0 ; i < n; i++){
        cin >> a[i];
        s+=abs(a[i]);
        }
    cout<<s<<endl;
}