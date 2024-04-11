#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n; char s[N];
int dis(int x,int y) {
    return min(abs(x-y),abs(-abs(x-y)+26));
}
int cac(int pos){
    int tmp=dis(s[pos]-'A','A'-'A')+dis(s[pos+1]-'A','C'-'A')+dis(s[pos+2]-'A','T'-'A')+dis(s[pos+3]-'A','G'-'A');
    return tmp;
}
int main(){
    scanf("%d%s",&n,s+1);
    int ans=N;
    for(int i=1;i<=n-3;i++){
        ans=min(ans,cac(i));
    }
    cout<<ans<<endl;
}