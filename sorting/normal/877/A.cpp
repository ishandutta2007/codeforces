#include<iostream>

using namespace std;

int main ()
{
    int i;
    string s;
    int br=0;

    cin>>s;

    for(i=0;i<=(int)s.size()-5;i++)
    {
        if(s[i]=='D' && s[i+1]=='a' && s[i+2]=='n' && s[i+3]=='i' && s[i+4]=='l')br++;
    }
    for(i=0;i<=(int)s.size()-4;i++)
    {
        if(s[i]=='O' && s[i+1]=='l' && s[i+2]=='y' && s[i+3]=='a')br++;
    }
    for(i=0;i<=(int)s.size()-5;i++)
    {
        if(s[i]=='S' && s[i+1]=='l' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='a')br++;
    }
    for(i=0;i<=(int)s.size()-3;i++)
    {
        if(s[i]=='A' && s[i+1]=='n' && s[i+2]=='n')br++;
    }
    for(i=0;i<=(int)s.size()-6;i++)
    {
        if(s[i]=='N' && s[i+1]=='i' && s[i+2]=='k' && s[i+3]=='i' && s[i+4]=='t' && s[i+5]=='a')br++;
    }

    if(br==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}