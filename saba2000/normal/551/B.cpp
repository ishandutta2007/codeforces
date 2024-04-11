#include<bits/stdc++.h>
using namespace std;
int A[200],B[200],C[200],T[200]={0},ans=0,ans1=0,ans2=0;
int main()
{string a,b,c;
cin>>a>>b>>c;
for (int i=0; i<a.size(); i++)
{A[a[i]]++;
T[a[i]]++;
}
for (int i=0; i<b.size(); i++)
B[b[i]]++;
for (int i=0; i<c.size(); i++)
C[c[i]]++;
for (int i=0; i<=a.size(); i++)
{int bb,p=0;
if (i!=0)
for (int j='a'; j<='z'; j++)
{A[j]-=C[j];
if (A[j]<0) {p=1;break;}}
if (p==1) break;
bb=a.size();
for (int j='a'; j<='z'; j++)
if (B[j]!=0) bb=min(bb,A[j]/B[j]);
if (ans<bb+i) {ans=bb+i;ans1=i;ans2=bb;}

}
for (int i=0; i<ans1; i++)
cout<<c;
for (int i=0; i<ans2; i++)
cout<<b;
for (int i='a'; i<='z'; i++)
T[i]-=ans1*C[i]+ans2*B[i];

for (int i='a'; i<='z'; i++){
for (int j=0; j<T[i]; j++)
cout<<(char)i;
}


}