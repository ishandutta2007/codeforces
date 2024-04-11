#include <iostream>
# include <vector>
# include<algorithm>
# include <string>
using namespace std;
int n,k;
string s;
bool check(int idx)
{
    bool a[26]={0};
    if (idx>=1)
        a[(int)s[idx-1]-'a']=1;
    if (idx>=2)
        a[(int)s[idx-2]-'a']=1;
    int now=(int)s[idx]-'a';
    now++;
    for (int i=now;i<k;i++)
    {
        if (a[i]==0)
        {
            s[idx]=char(i+97);
            return 1;
        }
    }
    return 0;
}
bool rep(int idx)
{
    bool a[26]={0};
    if (idx>=1)
        a[(int)s[idx-1]-'a']=1;
    if (idx>=2)
        a[(int)s[idx-2]-'a']=1;
    for (int i=0;i<k;i++)
    {
        if (a[i]==0)
        {
            s[idx]=char(i)+'a';
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin>>n>>k;
    cin>>s;
    int h=-1;
    for (int i=n-1;i>=0;i--)
    {
        if (check(i))
        {
            h=i+1;
            break;
        }
    }
    if (h==-1)
        cout<<"NO"<<endl;
    else
    {

        for (int i=h;i<n;i++)
        {
            if (!rep(i))
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<s<<endl;
    }
}