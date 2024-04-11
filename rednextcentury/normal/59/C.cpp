# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
int k;
bool vis[1000];
int main()
{
    cin>>k;
    string s;
    cin>>s;
    int n=s.length();
    for (int i=0;i<n;i++)
    {
        if (s[i]!='?' && s[n-i-1]!='?')
        {
            if (s[i]==s[n-i-1])
            {
                if (s[i]-'a'+1>k)
                {
                    cout<<"IMPOSSIBLE"<<endl;
                    return 0;
                }
                else
                    vis[s[i]-'a']=1;
            }
            else
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    int num=0;
    for (int i=n-1;i>=0;i--)
    {
        if (s[i]=='?')
        {
            if (s[n-i-1]!='?')
            {
                if (s[i]-'a'+1>k)
                {
                    cout<<"IMPOSSIBLE"<<endl;
                    return 0;
                }
                s[i]=s[n-i-1];
                vis[s[i]-'a']=1;
            }
            else
            {
                if (i==n/2 && n%2)
                    num+=2;
                else
                num++;
            }
        }
    }
    num/=2;
    for (int i=0;i<k;i++)
        if (!vis[i])
            num--;
        if (num<0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    for (int i=0;i<n;i++)
    {
        if (s[i]=='?')
        {
            if (s[n-i-1])
            {
                if (num)
                    s[i]=s[n-i-1]='a',num--;
                else
                {
                    int id=0;
                    for (int j=0;j<k;j++)
                    {
                        if (!vis[j])
                        {
                            vis[j]=1;
                            id=j;
                            break;
                        }
                    }
                    s[i]=s[n-i-1]=char(id+'a');
                }
            }
        }
    }
    cout<<s<<endl;
}