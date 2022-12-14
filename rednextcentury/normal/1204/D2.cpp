#include<bits/stdc++.h>
using namespace std;
int cur[1000005];
int ret[1000005];
int add[1000005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    cur[0]=1;
    memset(ret,-1,sizeof(ret));
    int zeros=(s[0]=='0');

    for (int i=1;i<s.size();i++){
        zeros+=(s[i]=='0');
        cur[i]=max(zeros,cur[i-1]+(s[i]=='1'));
        if (s[i]=='0')ret[i]=0;
    }

    int n=s.size();
    int num=1;
    for (int i=n-2;i>=0;i--)
    {
        if (cur[i]!=cur[i+1])add[i+1]+=num-1,num=1;
        else num++;
    }
    if (num>1)add[0]=num-1;
    int ones=0;
    for (int i=n-1;i>=0;i--)
    {
        ones+=add[i];
        if (ones && ret[i]==-1)
            ret[i]=1,ones--;
        else ret[i]=0;
    }
    for (int i=0;i<n;i++)cout<<ret[i];
    cout<<endl;
}