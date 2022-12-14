#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int num=0;
    int cnt[200]={0};
    for (int i=0;i<n;i++)
    {
        if (++cnt[tolower(s[i])]==1)
            num++;
    }
    if (num==26)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}