#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,a[200000],k[200000],pos[200000];
pair<int,int> p[200000];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],p[i]=make_pair(a[i],n-i);
    sort(p,p+n);
    cin>>m;
    int MAX=-1;
    for(int i=0;i<m;i++)cin>>k[i]>>pos[i],MAX=max(MAX,k[i]);
    vector<int> v[200000];
    for(int i=1;i<=MAX;i++){
        v[i]=v[i-1];
        v[i].push_back(n-p[n-i].second);
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<m;i++){
        cout<<a[v[k[i]][pos[i]-1]]<<endl;
    }
}