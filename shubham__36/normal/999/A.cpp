#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n,m,ans=0;
    bool b=true;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<=m && b) ans++;
        else b=false;
    }
    b=true;
    for(int i=n-1;i>=0;i--){
        if(a[i]<=m && b) ans++;
        else b=false;
    }
    cout << min(ans,n);
    return 0;
}