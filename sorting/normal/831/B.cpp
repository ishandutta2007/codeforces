#include<iostream>

using namespace std;

int main ()
{
    string s1,s2,a,res="";
    int l,i,j;
    bool x;
    char c;

    ios::sync_with_stdio(false);

    cin>>s1>>s2>>a;

    l=a.size();

    for(i=0;i<l;i++)
    {
        x=false;
        for(j=0;j<26;j++)
        {
            if(s1[j]==a[i])
            {
                x=true;
                break;
            }
        }
        if(x==true)
        {
            res=res+s2[j];
            continue;
        }
        x=false;

        for(j=0;j<26;j++)
        {
            c=(char)s1[j]+'A'-'a';
            if(c==a[i])
            {
                x=true;
                break;
            }
        }

        if(x==true)
        {
            c=(char)s2[j]+'A'-'a';
            res=res+c;
        }
        else res=res+a[i];
    }

    cout<<res<<endl;

    return 0;
}