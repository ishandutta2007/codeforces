#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5;

int a[sz];

int main()
{
    int i,j,k,n,m,x,y,l;
    cin >> n >> k;
    int ans=k/n;
    if(k%n) ans++;
    cout << ans << endl;
}