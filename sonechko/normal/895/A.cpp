#include<bits/stdc++.h>
using namespace std;
#define ld long double
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    int ans=360;
    for (int i=0; i<n; i++)
    {
        int res=0;
        for (int j=i; ; j=(j+1)%n)
        {
            res+=a[j];
            if (res==360) break;
            ans=min(ans,abs(360-res-res));
        }
    }
    cout<<ans<<endl;
}
/**
 
4
90 90 90 90
 
0
 
3
100 100 160
 
40
 
1
360
 
360
 
4
170 30 150 10
 
0
**/