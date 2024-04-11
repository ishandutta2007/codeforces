#include<bits/stdc++.h>
using namespace std;
string k="Bulbasaur";
int a[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int num=0;
    for (int i=0;i<n;i++)
    {
        a[s[i]]++;
    }
    for (int i=0;i<n;i++)
    {
        bool can=1;
        for (int j=0;j<9;j++)
        {
            if (a[k[j]]>0)
                a[k[j]]--;
            else
                can=0;
        }
        if (can)num++;
        else break;
    }
    cout<<num<<endl;
}