#include<bits/stdc++.h>
using namespace std;
main()
{

   int n;
   cin >> n;
   string s;
   cin >> s;
   int x=0,y=0;
   int ans=0;
   for (int i=0; i<n-1; i++)
   {
       if(s[i]=='U') y++;
       else x++;
       if(x==y && s[i]==s[i+1]) ans++;
   }
   cout<<ans<<endl;

}