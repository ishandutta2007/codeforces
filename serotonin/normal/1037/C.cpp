#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

char a[sz],b[sz];

int main()
{
    int i,j,k,t,x,y,z,n,m,s;
    cin >> n;
    scanf("%s %s", a, b);
    int ans=0;
    for(i=0;i<n;i++) {
        if(a[i]!=b[i]) {
            if(i<n-1 && a[i+1]!=b[i+1] && a[i]!=a[i+1]) {
                ans++;
                i++;
            }
            else ans++;
        }
    }
    cout << ans << endl;
}