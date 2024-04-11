#include<bits/stdc++.h>
using namespace std;
int M=1000000007;
int p[1000009];
int main()
{int ans=0;
p[1]=1;
for (int i=2; i<=1000000; i++)
p[i]=(2*p[i-1]+1)%M;
string s;
int k=0;
cin>>s;
while(s[k]=='b') k++;
for (int i=k; i<s.size(); i++)
if (s[i]=='b') {ans=(p[i-k]+ans)%M; k++;}
cout<<ans<<endl;
}