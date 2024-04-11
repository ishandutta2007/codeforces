#include<bits/stdc++.h>
using namespace std;
string str1;
string str2;
int n,m,flag=1;
using namespace std;
int main()
{
    cin>>n>>m;
    cin>>str1;cin>>str2;
    if (str1[0]=='<'&&str2[0]=='^') flag=0;
    if (str1[0]=='>'&&str2[m-1]=='^') flag=0;
    if (str1[n-1]=='<'&&str2[0]=='v') flag=0;
    if (str1[n-1]=='>'&&str2[m-1]=='v') flag=0;
    if (flag) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    return 0;
}