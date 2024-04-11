#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
char s[20];
int cnt[12];
LL f[20];
LL ans=0;
LL cac(vector<int> v) {
   LL sum=0;
    for(int i=0;i<v.size();i++)
        sum+=v[i];
    LL tmp=f[sum];
    for(int i=0;i<v.size();i++)
        tmp/=f[v[i]];
    return tmp;    
}
void dfs(vector<int> v) {
    int sz = v.size();
    
    if(sz == 10) {
        ans += cac(v);
        if(v[0]>=1) {
            v[0]--;
            ans -= cac(v);
        }
        return;
    }

    if (cnt[sz] == 0) {
        v.push_back(0);
        dfs(v);
        v.pop_back();
        return;
    }
    for(int i=1;i<=cnt[sz];i++) {
        v.push_back(i);
        dfs(v);
        v.pop_back();
    }
}

int main() {
    f[0]=1;
    for(int i=1;i<=19;i++)
        f[i]=f[i-1]*(LL)i;
    
    scanf("%s", s);
    for(int i=0;s[i];i++)
        cnt[s[i]-'0'] ++;
    vector<int> v;
    dfs(v);
    cout<<ans<<endl;
}