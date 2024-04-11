#include <iostream>
#include <map>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int n,a[N];char s[N];
LL ans = 0;
map<int,int> mp;
LL getAns(int ban) {
    mp.clear();
    LL tmp = 0;
    for(int i=1;i<=n;i++) {
        if(ban==-1)
            tmp += mp[a[i]];
        else
            tmp += mp[a[i] ^ (1<<ban)];
        mp[a[i]] ++;
    }
    return tmp;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s",s);
        int mask=0; 
        int cnt[30] = {0};
        for(int j=0;s[j];j++) cnt[s[j]-'a'] ++;
        for(int j=0;j<26;j++) if(cnt[j]%2==1) mask |= 1<<j;
        a[i] = mask;
    }
    for(int i=-1;i<26;i++) {
        ans += getAns(i);
    }
    cout << ans << endl;
}