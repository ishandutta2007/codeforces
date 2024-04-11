#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n,m,ans=0,j=0;
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        if(b[j]>=a[i]){
            ans++;
            j++;
        }
        if(j>=m) break;
    }
    cout << ans << endl;
    return 0;
}