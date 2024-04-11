#include<stdio.h>
#include<string.h>
#include <string>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include <map>
using namespace std;
int out[11111111];
int main()
{
   // freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int> > a;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(make_pair(x,y),i));
    }
    sort(a.begin(),a.end());
    int last=0;
    while(!a.empty()){
        out[a[0].second]=(a[0].first.first);        
        for(int j=1;j<a.size() && a[j].first.first==a[0].first.first;j++)
            a[j].first.first++;
        a[0].first.first=11111111;
        sort(a.begin(),a.end());
        a.pop_back();
    }
    for(int i=0;i<n;i++)
        cout<<out[i]<<' ';
    return 0;
}