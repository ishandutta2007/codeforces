#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s="";
    for (int i=0; i<k; i++)
    {
        char ch=(i+'a');
        s+=ch;
    }
    int p=0;
    while (s.size()<n)
    {
        if (p==0) s+="a"; else s+="b";
        p=(1-p);
    }
    cout<<s<<endl;

}