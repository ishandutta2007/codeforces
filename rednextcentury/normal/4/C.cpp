# include <map>
# include <iostream>
# include <string>
using namespace std;
int main()
{
int n;
cin>>n;
map<string,int> m;
for (int i=0;i<n;i++)
{
     string s;
     cin>>s;
     if (++m[s]==1)
        cout<<"OK"<<endl;
     else
     {
         cout<<s<<m[s]-1<<endl;
         int d=m[s]-1;
         int loc=0;
         char a[10000];
         while (d>0)
         {
             a[loc]=char((d%10)+48);    
             loc++;
             d=d/10;
         }
         for (int c=loc-1;c>=0;c--)
               s+=a[c];
         m[s]++;
     }
}
}