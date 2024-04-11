#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    char ch;
    cin>>n>>ch>>m;
    cin>>k;
    m=m+n*60+k;
    if (m/60%24<10&&m%60<10) cout<<"0"<<m/60%24<<":0"<<m%60<<endl; else
    if (m/60%24<10) cout<<"0"<<m/60%24<<":"<<m%60<<endl; else
    if (m%60<10) cout<<m/60%24<<":0"<<m%60<<endl; else
    cout<<m/60%24<<":"<<m%60<<endl;
}