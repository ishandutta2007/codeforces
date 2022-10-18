#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if (m==1&&n>1) {cout<<"-1"<<endl; return 0;}
    if (m>n) {cout<<-1<<endl; return 0;}
    if (m==1) {cout<<"a"; return 0;}
    for (int i=1; i<=n-(m-2); i++)
        if (i%2==1) cout<<"a"; else cout<<"b";
    for (int i=1;  i<=m-2; i++)
    {
        char ch='a'+(i+1);
        cout<<ch;
    }
    cout<<endl;
}