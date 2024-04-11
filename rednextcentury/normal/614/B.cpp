# include<bits/stdc++.h>
using namespace std;
char x[1000000];
int main()
{
    int n;
    cin>>n;
    string k="P";
    int len=0;
    bool allzero=0;
    for (int i=0;i<n;i++)
    {
        scanf("%s",&x);
        string s=x;
        int m=s.length();
        bool p=0;
        int num=0;
        for (int j=0;j<m;j++)
        {
            if (s[j]!='1' && s[j]!='0')
                p=1;
            if (s[j]=='1')
                num++;
        }
        if (s[0]=='0')
            allzero=1;
        if (num>1 || p)
            k=s;
        else
            len+=m-1;
    }
    if (allzero)
    {
        cout<<0<<endl;
        return 0;
    }
    if (k=="P")
    {
        cout<<"1";
        for (int i=0;i<len;i++)
            cout<<0;
        cout<<"\n";
        return 0;
    }
    cout<<k;
    for (int i=0;i<len;i++)
        cout<<0;
    cout<<"\n";
}