#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=1000000+10;
typedef long long LL;
int n;
vector<int> v[N];
vector<int> vec;
int s[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        for(int j=1;j<=x;j++){
            int y; scanf("%d",&y); v[i].push_back(y);
        }
        bool ok=1;
        for(int j=1;j<v[i].size();j++){
            if (v[i][j]>v[i][j-1])ok=0;
        }
        if(ok)vec.push_back(i);
    }
    for(auto x: vec) s[v[x][0]] ++;
    for(int i=1;i<N;i++)s[i]+=s[i-1];
    LL ans=0;
    for(auto x: vec) {
        ans=ans+s[v[x][(int)v[x].size()-1]];
    } 
    ans=1LL*n*n-ans;
    cout<<ans<<endl;
}