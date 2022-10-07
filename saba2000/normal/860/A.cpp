#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
bool c(char s)
{
    if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u') return 1;
    return 0;
}
main()
{
   string s;
   cin>>s;

   int r=0;
   while(r!=s.size())
   {
       int t=0,d=0;
       int f[5009];
       for (int i='a'; i<='z'; i++)
       f[i]=0;
   for (int j=r; j<s.size(); j++)
   {
     if(f[s[j]]==0) d++;
     t++;
     f[s[j]]=1;
     if(c(s[j])==1)  {for (int i='a'; i<='z'; i++)
       f[i]=0; d=0; t=0;}

     if(c(s[j])==0 && t>=3 && d!=1 ) {
     for (int i=r; i<j; i++) cout<<s[i]; cout<<" "; r=j; break;}
     if(j==s.size()-1)
     {for (int i=r; i<s.size(); i++) cout<<s[i];
     cout<<endl;
         r=s.size();
         break;
     }
   }
   }


}