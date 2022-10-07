#include<bits/stdc++.h>
using namespace std;
int s=0,z,p[3],nt,no,c;
int main()
{string k,a="",b="",x="",y="";
cin>>k;
for (int i=0; i<k.size();i++)
{s+=k[i]-'0';
if (k[i]=='0') z=1; 
p[(k[i]-'0')%3]++;}
if (s%3==0) {cout<<k<<endl; return 0;}
else if (s%3==1) {nt=2;  no=1;}
else if (s%3==2) {nt=1; no=2;}
//cout<<nt<<" "<<no<<endl;
for (int i=k.size()-1; i>=0; i--){
if (no==0 || (k[i]-'0')%3!=1) {//cout<<1<<endl;
 a=k[i]+a; }
 if ( (k[i]-'0')%3==1 && no>0) no--;
}
for (int i=k.size()-1; i>=0; i--){
if (nt==0 || (k[i]-'0')%3!=2) 
{b=k[i]+b; }
if ( (k[i]-'0')%3==2 && nt>0) nt--;
}

if (no>0 && nt>0) {cout<<-1<<endl; return 0;}
c=0;
if (no==0)
for (int i=0; i<a.size(); i++)
if (a[i]!='0' || c==1) {//cout<<1<<endl;
 x+=a[i]; if (a[i]!='0') c=1;} c=0;
if (nt==0)
for (int i=0; i<b.size(); i++)
if (b[i]!='0' || c==1) {y+=b[i]; if (b[i]!='0') c=1;}
if (x.size()==0 && y.size()==0) {if (z==0) cout<<-1<<endl; else cout<<0<<endl; return 0;}
if (x.size()<y.size()) cout<<y<<endl;
else cout<<x<<endl;
}