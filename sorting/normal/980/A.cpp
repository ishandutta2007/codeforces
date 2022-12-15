#include<iostream>

using namespace std;

int main ()
{
    string s;

    cin>>s;

    int n=s.size(),i,cnt=0;

    for(i=0;i<n;i++)
    {
        if(s[i]=='-')
            cnt++;
    }

    int cnt2=n-cnt;

    if(cnt2==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    if(cnt%cnt2==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}