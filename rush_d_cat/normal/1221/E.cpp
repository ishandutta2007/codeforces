#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int q,a,b; char s[N];
int main() {
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&a,&b);
        scanf("%s",s+1);
        int ans = 0;
        vector<int> v;
        for(int i=1,j=1;s[i];i=j){
            if(s[i] == 'X') {
                j++;
            } else {
                while(s[j] && s[j]==s[i]) j++;
                int len = j - i;
                if (len < b) continue;
                v.push_back(len);
            }
        }
        bool win=0; int cnt=0;
        for(auto x: v) {
            if(x>=b && x<a) win=1;
            if(x>=2*b) cnt++;
        }
        if(cnt>=2) win=1;
        if(win) {
            printf("NO\n"); continue;
        }

        if(cnt==0) {
            if(v.size()%2 == 0) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            int mx = *max_element(v.begin(),v.end());
            bool ok = 0;
            for(int x=0;x+a<=mx;x++) {
                int l = x;
                int r = mx - (x+a);
                if (l < a && l >= b) continue;
                if (r < a && r >= b) continue;
                if (l >= 2 * b) continue;
                if (r >= 2 * b) continue;
                
                int sz = (int)v.size() - 1;
                if (l >= a) sz++;
                if (r >= a) sz++;
                if (sz % 2 == 0) ok = 1;
            }
            printf("%s\n", ok ? "YES" : "NO");
        }
    }
}