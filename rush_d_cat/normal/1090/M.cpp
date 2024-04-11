#include <iostream>
#include <vector>
using namespace std;
const int N=100000+10;
int n,k,a[N];
vector< pair<int,int> > v;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    v.push_back(make_pair(1,1));
    for(int i=1,j=1;i<=n;i=j){
        while(j<=n && a[i]==a[j]) j++;
        if(i+1!=j) v.push_back(make_pair(i,j-1));
    }
    v.push_back(make_pair(n,n));
    int ans=0;
    for(int i=1;i<v.size();i++){
        ans=max(ans,v[i].first-v[i-1].second+1);
    }
    cout<<ans<<endl;
}