 #include <bits/stdc++.h>
using namespace std;
int a[101][101];
int c[1001];
int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int ans=0;
    for (int i=1;i<n;i++)
    {
        if (s[i]=='.' && s[i-1]=='.')
            ans++;
    }
    for (int i=0;i<m;i++)
    {
        int idx;char x;
        cin>>idx>>x;
        if (x!='.' && s[idx-1]!='.')
            ;
        else if (x!=s[idx-1])
        {
            s[idx-1]=x;
            if (idx==1 && idx==n)
                ans+=0;
            else if (idx==1)
            {
                if (s[idx]=='.')
                    ans+=(x=='.'?1:-1);
            }
            else if (idx==n)
            {
                if (s[idx-2]=='.')
                    ans+=(x=='.'?1:-1);
            }
            else
            {

                if (s[idx-2]=='.')
                    ans+=(x=='.'?1:-1);

                if (s[idx]=='.')
                    ans+=(x=='.'?1:-1);
            }
        }
        cout<<ans<<endl;
    }
}