#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    string ans="";
    if (a>b)
    {
        for (int i=1; i<=x+1; i++)
        if (i%2==1) {ans+="0"; a--;} else {ans+="1"; b--;}
    } else
    {
        for (int i=1; i<=x+1; i++)
        if (i%2==0) {ans+="0"; a--;} else {ans+="1"; b--;}
    }
    for (int i=0; i<ans.size(); i++)
    {
        while (a>0&&ans[i]=='0')
        {
            a--;
            cout<<0;
        }
        while (b>0&&ans[i]=='1')
        {
            b--;
            cout<<1;
        }
        cout<<ans[i];
    }
}