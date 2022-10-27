#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 100000 + 10;
int n,m;

vector<int> v[N];int sum[N]; set<int> st;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int s,r;scanf("%d%d",&s,&r);
        v[s].push_back(r);
    }
    for(int i=1;i<=m;i++){
        sort(v[i].begin(),v[i].end(),cmp);
        st.insert(i);
    }

    LL ans=0;
    for(int i=1;i<=n;i++){
        vector<int> del;
        LL tmp=0;
        for(auto x:st){
            if(v[x].size()<i)del.push_back(x);
            else{
                sum[x] += v[x][i-1];
                if(sum[x]<0) del.push_back(x);
                else tmp += sum[x];
            }
        }
        for(auto x:del) st.erase(x);
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}