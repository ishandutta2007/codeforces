#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5;

int a[105];

int main()
{
    int n,i,j,k;
    cin >> n;
    for(i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int x=0;
    for(i=0; i<n; i+=2) x+=a[i+1]-a[i];
    cout << x << endl;
}