#include<iostream>
using namespace std;
string s;
int cur[26],p,sum;
bool flag;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='?')p++;
        if(i-25>0&&s[i-26]=='?')p--;
        cur[s[i]-'A']++;
        if(i-25>0)cur[s[i-26]-'A']--;
        sum=0;
        for(int j=0;j<=25;j++)
        {
            if(cur[j])sum++;
            //cout<<sum<<endl;
        }
        if(sum+p==26)
        {
            flag=true;
            int cnt=0;
            for(int j=i-25;j<=i;j++)
            {
                if(s[j]=='?')
                {
                    while(cur[cnt])cnt++;
                    s[j]=cnt+'A';
                    cnt++;
                }
            }
            break;
        }
    }
    if(flag)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?')s[i]='A';
        }
        cout<<s<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}