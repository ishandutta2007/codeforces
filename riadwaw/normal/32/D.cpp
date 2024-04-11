#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    int n,m,k;
    vector<pair<int,pair<int,int> > > v;
    bool a[333][333];
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='*')
                a[i][j]=true;
            else
                a[i][j]=false;
        }

    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
            for(int k=1,z=min(min(i,n-i-1),min(j,m-1-j));k<=z;k++)
                if(a[i][j] && a[i][j-k] && a[i][j+k] && a[i-k][j] && a[i+k][j])
                    v.push_back(make_pair(k,make_pair(i+1,j+1)));
    if(v.size()<k)
        cout<<-1;
    else{
        sort(v.begin(),v.end());
        {
            cout<<v[k-1].second.first<<' '<<v[k-1].second.second<<'\n';
            cout<<v[k-1].second.first-v[k-1].first<<' '<<v[k-1].second.second<<'\n';
            cout<<v[k-1].second.first+v[k-1].first<<' '<<v[k-1].second.second<<'\n';
            cout<<v[k-1].second.first<<' '<<v[k-1].second.second-v[k-1].first<<'\n';
            cout<<v[k-1].second.first<<' '<<v[k-1].second.second+v[k-1].first<<'\n';
        }
    }
    return 0;
}