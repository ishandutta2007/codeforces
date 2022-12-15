#include<iostream>

using namespace std;

int main ()
{
    int n,m,l,r,i,j;
    char c1,c2;

    cin>>n>>m;

    string s;

    cin>>s;

    for(i=0;i<m;i++)
    {
        cin>>l>>r>>c1>>c2;
        l--;
        r--;

        for(j=l;j<=r;j++)
        {
            if(s[j]==c1)s[j]=c2;
        }
    }

    cout<<s<<endl;

    return 0;
}