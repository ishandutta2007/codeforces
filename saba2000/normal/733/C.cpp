#include<iostream>
using namespace std;
int a[1000],b[1000],n,k,ans,p=1;
char ans2[1000];
int ans1[1000];
bool check(int x,int y, int z)
{//cout<<x<<" "<<y<<" "<<z<<endl;
if (x==y) return true;
int s=0,ma=a[x],c=0,u;
for (int i=x; i<=y; i++)
{s+=a[i];
if (ma<a[i]) ma=a[i];
if (i!=y && a[i]!=a[i+1]) c=1;}
//cout<<c<<" "<<s<<" "<<ma<<" "<<endl;

if (c==0 || s!=z) return false;
for (int i=x; i<=y; i++)
if (a[i]==ma && (i!=x && a[i-1]<ma || i!=y && a[i+1]<ma)) u=i;
//cout<<u<<endl;
int o=u;
if (a[u-1]==ma && u!=x){
ans1[ans]=u-x+p;
ans2[ans]='R'; ans++; o++;}

while(u>x)
{ans1[ans]=u-x+p;
ans2[ans]='L';
ans++;
u--;}
for (int i=0; i<y-o; i++)
{ans1[ans]=p;
ans2[ans]='R';
ans++;}

return true;
}
main()
{cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
cin>>k;
for (int i=0; i<k; i++)
cin>>b[i];
int x=0,w=0,y=0;
if (b[0]<a[0]) {cout<<"NO"<<endl; return 0;} 
for (int i=0; i<n; i++)
{
w+=a[i];
 if (w>b[y] || (w<b[y] && i==n-1) || y==k) {cout<<"NO"<<endl; return 0;} 
if (w<b[y]) continue;
if (check(x,i,b[y])==0) 
{cout<<"NO"<<endl; return 0;} 
else {x=i+1; y++; w=0; p++;}
} 
if (y<k){cout<<"NO"<<endl; return 0;} 
cout<<"YES"<<endl;
for (int i=0; i<ans; i++)
cout<<ans1[i]<<" "<<ans2[i]<<endl;

}/*
6
1 2 2 2 1 2
2
5 5*/