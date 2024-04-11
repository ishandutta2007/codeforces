#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int N = 2e5 + 2;

int q, n;
char s[N], t[N];
vector<int> sl, sr, tl, tr;

int main(){
    scanf("%d", &q);
    while(q--){
        sl.clear();
        sr.clear();
        tl.clear();
        tr.clear();
        scanf("%d%s%s", &n, s + 1, t + 1);
        if(s[1] != t[1] || s[n] != t[n]){
            puts("-1");
            continue;
        }
        int l = -1, r = -1;
        for (int i = 1; i <= n; i++){
            if(s[i] == '1'){
                if(r != -1)
                    r++;
                else
                    l = r = i;
            }
            else if(r != -1){
                sl.push_back(l);
                sr.push_back(r);
                r = -1;
            }
        }
        if(r != -1){
            sl.push_back(l);
            sr.push_back(r);
            r = -1;
        }
        for (int i = 1; i <= n; i++){
            if(t[i] == '1'){
                if(r != -1)
                    r++;
                else
                    l = r = i;
            }
            else if(r != -1){
                tl.push_back(l);
                tr.push_back(r);
                r = -1;
            }
        }
        if(r != -1){
            tl.push_back(l);
            tr.push_back(r);
            r = -1;
        }
        if(sl.size() != tl.size()){
            puts("-1");
            continue;
        }
        long long ans = 0;
        for (int i = 0; i < sl.size(); i++)
            ans += abs(sl[i] - tl[i]) + abs(sr[i] - tr[i]);
        printf("%lld\n", ans);
    }
    return 0;
}