#include<iostream>
#include<vector>

using namespace std;

vector<int> a,b;

#define endl "\n"

int main ()
{
    string s;
    int l,i;

    ios::sync_with_stdio(false);

    cin>>s;

    l=s.size();

    for(i=0;i<l;i++)
    {
        if(s[i]=='l')a.push_back(i+1);
        else b.push_back(i+1);
    }
    l=b.size();
    for(i=0;i<l;i++)
    {
        cout<<b[i]<<endl;
    }
    l=a.size();
    for(i=l-1;i>=0;i--)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}