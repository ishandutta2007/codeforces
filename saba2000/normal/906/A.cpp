#include<bits/stdc++.h>
using namespace std;
int f[509],g[509];
main()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i='a'; i<='z'; i++)
        f[i]=1;
    for (int i=0; i<n; i++)
    {
        char k;
    int fl=0;
    string t="";
        for (int i='a'; i<='z'; i++)
            g[i]=0;
            for (int i='a'; i<='z'; i++)
            {fl+=f[i];
            if(f[i]) t+=i;}
        string b;
        cin>>k>>b;
        if(k=='.')
        {
            for (int i=0; i<b.size(); i++)
            g[b[i]]=1;
            for (int i='a'; i<='z'; i++)
                if(g[i]==1) f[i]=0;
        }
        if(k=='!')
        {
            if(fl==1) ans++;
            for (int i=0; i<b.size(); i++)
            g[b[i]]=1;
            for (int i='a'; i<='z'; i++)
                if(g[i]==0) f[i]=0;
        }
        if(k=='?')
        {
            if(fl==1 && b!=t) ans++;
            f[b[0]]=0;
        }
    }
    cout<<ans<<endl;

}