#include<iostream>
using namespace std;
int n,k,s[1000000],a,b,ans,p;
main ()
{
cin>>n>>k;
for(int i=0; i<n; i++)
cin>>s[i];
if (n==1) {cout<<s[0]<<endl; return 0;}
a=s[n-1]; b=s[n-1]+s[n-2];
p=n-k;
while (a<=b) 
{int c=(a+b)/2,i=0,j=n-1,q=0,ch=1; //6
while (true)
{for (j; j>=0; j--)
if (i>=j) {ch=0;break;}
else if (s[i]+s[j]<=c) {q++; break;}
if (ch==0) break;
i++;
j--;
}
if (q>=p) ans=c;
if (q>=p) b=c-1;
else a=c+1;
}
cout<<ans<<endl;
}