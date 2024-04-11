#include<iostream>
#include<cstring>
using namespace std;

long long n,i;
long long j,pasuxi=0;
string s;
main()
{
    cin>>n;
    cin>>s;
   i=0;
   while(s[i]=='<')
   {
       pasuxi++;
       i++;
   }
       i=n-1;
   while(s[i]=='>')
   {
       pasuxi+=1;
       i--;
   }
    cout<<pasuxi;    }