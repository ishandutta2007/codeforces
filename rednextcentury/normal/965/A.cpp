#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,s,p;
    cin>>k>>n>>s>>p;
    int need = (n/s)+(n%s>0);
    int tot = need*k;
    int packs = tot/p + (tot%p>0);
    cout<<packs<<endl;
}