#include<bits/stdc++.h>
using namespace std;
int a[200000];
main()
{
    int n;
    cin >> n;
    for (int i=0; i < n; i++)
        cin >> a[i];
    string s; cin >> s;
    int L = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(s[i]=='0'){
        sort(a+L,a+i+1);
        L = i+1;}
    }
    sort(a+L,a+n);
    for (int i=0; i < n; i++)
    if(a[i] < a[i-1]) 
{
    cout <<"NO"<< endl;
    return 0;
}
cout <<"YES"<< endl;
}