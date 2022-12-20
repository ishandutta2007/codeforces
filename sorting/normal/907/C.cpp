#include<iostream>

using namespace std;

bool possible[27];
bool another[27];
int sum=26;

int main ()
{
    int n,j,i,res=0,p;
    char c;
    string s;

    for(j=0;j<26;j++)possible[j]=1;

    cin>>n;

    for(i=0;i<n && sum>1;i++)
    {
        cin>>c>>s;

        //cout<<sum<<" "<<c<<" "<<s<<endl;

        for(j=0;j<26;j++)another[j]=0;

        for(j=0;j<s.size();j++)
        {
            p=(int)s[j]-'a';
            another[p]=1;
        }

        if(c=='!')
        {
            for(j=0;j<26;j++)
            {
                if(another[j]==0)
                {
                    if(possible[j])
                    {
                        possible[j]=0;
                        sum--;
                    }
                }
            }
        }
        if(c=='.')
        {
            for(j=0;j<26;j++)
            {
                if(another[j]==1)
                {
                    if(possible[j])
                    {
                        possible[j]=0;
                        sum--;
                    }
                }
            }
        }
        if(c=='?')
        {
            p=(int)s[0]-'a';
            if(possible[p])
            {
                possible[p]=0;
                sum--;
            }
        }
    }

    for(i;i<n-1;i++)
    {
        cin>>c>>s;

        if(c=='?' || c=='!')res++;
    }
    for(i;i<n;i++)cin>>c>>s;

    cout<<res<<endl;

    return 0;
}