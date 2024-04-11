#include<bits/stdc++.h>
using namespace std;
int main()
{int n,a[100009],mi,ma,m;
cin>>n>>a[0]; mi=a[0]; ma=a[0];
m=n;
for (int i=1; i<n; i++)
{cin>>a[i];
mi=min(mi,a[i]); ma=max(ma,a[i]);
}
for (int i=0; i<n; i++)
if (a[i]==mi || a[i]==ma) m--;
cout<<m<<endl;
	
}