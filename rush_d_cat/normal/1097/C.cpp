#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

typedef long long LL;
const int N=500000+10;
int n;char s[N];
vector<int> L,R;
map<int,int> mp;
int main(){
    scanf("%d",&n);

    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        int mx=-N, mn=N;
        int sum=0;
        for(int j=0;s[j];j++){
            if(s[j]=='(') sum++;
            if(s[j]==')') sum--;
            mn = min(mn, sum);
        }

        if(sum>0 && mn>=0) {
            mp[sum] ++;
        }
        if(sum==0 && mn>=0) {
            cnt ++;
        }
        if(sum<0) {
            int len=strlen(s);
            int sum=0;
            for(int j=len-1;j>=0;j--){
                if(s[j]=='(')sum++;
                if(s[j]==')')sum--;
                mx = max(mx, sum);
            }
            if(mx <= 0) mp[sum] ++;
        }
    }

    int ans = cnt/2;
    for(auto p: mp) {
        if(p.first > 0)
            ans += min(p.second, mp[-p.first]);
    }
    cout << ans << endl;
}