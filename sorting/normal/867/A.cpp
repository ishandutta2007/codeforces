#include<iostream>

using namespace std;

int main ()
{
    string s;


    int n;
    cin>>n;

    cin>>s;

    int a=0,b=0;

    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            if(s[i]=='S')a++;
            else b++;
        }
    }

    if(a>b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}