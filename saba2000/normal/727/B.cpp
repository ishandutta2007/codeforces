#include<iostream>
using namespace std;
string a[1000];
int p[1000];
int n;
long long ans;
string s,b,k,ans1;
main()
{
cin>>s;
for (int i=0; i<s.length(); i++)
{if(s[i]<='z' && s[i]>='a' ){
if (b!=""){a[n]=b; b=""; n++;} continue;}
b+=s[i];}
a[n]=b; n++;

for (int i=0; i<n; i++)
{int t=0,d=0,r=0;
for (int j=0; j<a[i].size(); j++)
if (a[i][j]!='.') {t=t*10+int(a[i][j]-'0'); r++;}
else {d++; r=0;}
if (r==2 && d>0) ans+=t; else ans+=t*100;
}int c=0,e=0; 
int q=0;

if (ans%100==0) {ans/=100; c=1;} else
if (ans<100) q=1;
for (long long i=ans; i>0;i/=10)
{ans1=(char)(i%10+48)+ans1; e++;
if (c==0 && e==2 && i/10!=0) {ans1='.'+ans1; c=1; e=0;} 
else if (c==1 && e==3 && i/10!=0){ans1='.'+ans1; e=0;}
}
if (q==1 && ans1.size()==1) cout<<"0.0"<<ans1<<endl; else
if (q==1 && ans1.size()==2) cout<<"0."<<ans1<<endl; else 
cout<<ans1<<endl;

}