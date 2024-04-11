#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
            int l,r;
        cin>>l>>r;
        v.push_back(make_pair(l,0));
        v.push_back(make_pair(r,1));
}
sort(v.begin(),v.end());
int s=0;
for (int i=0; i<v.size(); i++)
{
    if(v[i].second==1) s--;
    else s++;
    if(s>2) {cout<<"NO"<<endl; return 0;}
}
cout<<"YES"<<endl;
}