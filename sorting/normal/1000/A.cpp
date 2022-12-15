#include<iostream>
#include<map>

using namespace std;

string a[101],b[101];

map<string,int> Map;

int main ()
{
    int n,i,res=0,j;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        Map[a[i]]++;
    }
    for(j=0;j<n;j++)
    {
        cin>>b[i];
        if(!Map[b[i]])
            res++;
        else
            Map[b[i]]--;
    }

    cout<<res<<endl;

    return 0;
}