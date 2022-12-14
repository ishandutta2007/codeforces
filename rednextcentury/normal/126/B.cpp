#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int F[1000000];
int n,m;
string s;
void FF()
{
    F[0]=-1;
    int i=0,j=-1;
    while(i<n)
    {
        while(j>=0 && s[i]!=s[j])
            j=F[j];
        i++,j++;
        F[i]=j;
    }
}
bool KMP()
{
    int ans=0;
    int i=0,j=0;
    while(i<n)
    {
        while(j>=0 && s[i]!=s[j])
            j=F[j];
        i++,j++;
        if (j==m)
        {
            ans++;
            j=F[j];
        }
    }
    if (ans>=3)
        return 1;
    return 0;
}
int main()
{
    cin>>s;
    n=s.length();
    FF();
    m=F[n];
    if (KMP())
        cout<<s.substr(0,m)<<endl;
    else if (F[F[n]]>0)
        cout<<s.substr(0,F[F[n]])<<endl;
    else
        cout<<"Just a legend"<<endl;
}