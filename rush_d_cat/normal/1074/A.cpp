#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=100000+10;

int n,m;
vector<int> v1,v2;
int main() {
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        v1.push_back(x);
    }
    v1.push_back(1e9);
    if(m==0) {
        return !printf("0\n");
    }
    for(int i=1;i<=m;i++){
        int x1,x2,y; scanf("%d%d%d",&x1,&x2,&y);
        if(x1==1) v2.push_back(x2);
    }
    sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end()); 
    int ans=1e9;
    int cnt=v2.size(),l=0;
    for(int i=0;i<v1.size();i++) {
        while(l<v2.size() && v2[l]<v1[i])cnt--,l++;
        ans = min(ans, cnt+i);
    }
    cout<<ans<<endl;
}
/*
0 2
1 100000000 4
1 100000000 2
*/