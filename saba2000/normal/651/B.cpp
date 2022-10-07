#include<bits/stdc++.h>
using namespace std;
int a[1009],ans;
int main()
{int n;
cin>>n; int p=0;
for (int i=0; i<n; i++)
{cin>>a[i]; int k=0;
for (int j=i-1; j>=0; j--)
if (a[i]==a[j])k++;
p=max(p,k);
}
cout<<n-1-p<<endl;

}