#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ch(a) (int(a-'a')+1)
#define mm(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define inf  0x7FFFFFFF
typedef long long ll;
const int Maxx=1e5+10;
int a[100][100];
int b[100][100];
int c[100][100];
int main()
{
    int t,n,m;
    cin>>t;
    // IOS;
    for(int i=0;i<=55;i++)
    {
        for(int j=0;j<=55;j++)
        {
            if((i+j)%2==1)
            {
                b[i][j]=1;
                c[i][j]=2;
            }
            else if((i+j)%2==0)
            {
                b[i][j]=2;
                c[i][j]=1;
            }
        }
    }
    string s;
    while(t--)
    {
        cin>>n>>m;
        s=" ";
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='W') a[i][j]=1;
                else if(s[j]=='R') a[i][j]=2;
                else if(s[j]=='.') a[i][j]=0;
            }
        }
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0) continue;
                if(a[i][j]!=b[i][j])
                {
                    flag=1;break;
                }
            }
        }
        if(!flag)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(b[i][j]==1) cout<<"W";
                    else if(b[i][j]==2) cout<<"R";
                }
                cout<<endl;
            }
        }
        else
        {
            flag=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(a[i][j]==0) continue;
                    if(a[i][j]!=c[i][j])
                    {
                        flag=1;break;
                    }
                }
            }
            if(!flag)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(c[i][j]==1) cout<<"W";
                        else if(c[i][j]==2) cout<<"R";
                    }
                    cout<<endl;
                }
            }
            else cout<<"NO"<<endl;
        }

    }
    return 0;
}