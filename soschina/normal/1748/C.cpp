#include <cstdio>
#include <map>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N];
map<long long, int> mp;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long sum = 0;
        int ans = 0;
        bool haszero = false;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i]){
                sum += a[i];
                mp[sum]++;
            }
            else{
                sum = 0;
                int maxres = 0;
                if(haszero){
                    for(auto pr : mp)
                        if(pr.second > maxres)
                            maxres = pr.second;
                }
                else
                    maxres = mp[0];
                haszero = true;
                ans += maxres;
                mp.clear();
                mp[0] = 1;
            }
        }
        int maxres = 0;
        if(haszero){
            for(auto pr : mp)
                if(pr.second > maxres)
                    maxres = pr.second;
        }
        else
            maxres = mp[0];
        ans += maxres;
        mp.clear();
        printf("%d\n", ans);
    }
    return 0;
}