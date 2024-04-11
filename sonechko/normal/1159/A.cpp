#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int kol=0;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        if (ch=='+') kol++; else kol=max(0,kol-1);
    }
    cout<<kol<<"\n";
}