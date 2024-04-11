#include<bits/stdc++.h>
using namespace std;

map<string,int> m;
string a[110];
int maxv=-100;
string ans;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],m[a[i]]++;
    for(int i=0;i<n;i++)if(m[a[i]]>maxv)maxv=m[a[i]],ans=a[i];
    cout<<ans<<endl;
    return 0;
}