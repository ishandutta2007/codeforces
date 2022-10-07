#include<bits/stdc++.h>
using namespace std;
int G[100]={0,1},n,s,ans;
main()
{
    for (int i =2; i <= 60; i++)
       if((G[i-1]+1)*(G[i-1]+2)/2 <= i) G[i]=G[i-1]+1;
       else G[i]=G[i-1];
    cin >> n;
    while(n--)
    {
        scanf("%d",&s);
        ans ^= G[s];
    }
    if(ans) cout << "NO";
    else cout <<"YES";
}