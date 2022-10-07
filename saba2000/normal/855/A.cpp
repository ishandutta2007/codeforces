#include<bits/stdc++.h>
using namespace std;
set<string> S;
main()
{int n;
cin>>n;
while(n--)
{
    string k;
    cin>>k;
    if(S.find(k)==S.end()){cout<<"NO"<<endl;}
    else cout<<"YES"<<endl;
    S.insert(k);
}

}