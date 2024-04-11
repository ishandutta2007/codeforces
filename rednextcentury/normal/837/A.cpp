#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    while(s.size()==0)
    getline(cin,s);
    int num=0;
    int mx=0;
    for (int i=0;i<n;i++)
    {
        char x=s[i];
        if (x==' ')
            mx=max(mx,num),num=0;
        else if (tolower(x)!=x)
            num++;
    }
    mx=max(mx,num);
    cout<<mx<<endl;
}