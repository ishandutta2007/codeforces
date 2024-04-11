#include <iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    int n,t,cs=0,ans=0,l=0;
    cin>>n>>t;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cs+=a[i];
        while(cs>t){
            cs-=a[l];
            l++;
        }
        if (i-l+1>ans) ans=i-l+1;
    }
    cout<<ans;
    return 0;
}