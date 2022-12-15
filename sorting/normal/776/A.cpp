#include<iostream>

using namespace std;

int main ()
{
    int n,i;
    string s1,s2,a,b;

    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s1>>s2;

    cout<<s1<<" "<<s2<<endl;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a>>b;

        if(a==s1)s1=b;
        else s2=b;

        cout<<s1<<" "<<s2<<endl;
    }

    return 0;
}