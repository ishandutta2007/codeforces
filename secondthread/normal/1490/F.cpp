#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    for (int tt=0; tt<T; tt++) {
        map<int, int> freq;
        int n; cin>>n;
        for (int i=0; i<n; i++) {
            int ai; cin>>ai;
            if (freq.count(ai)==0)
                freq[ai]=1;
            else
                freq[ai]=freq[ai]+1;
        }
        vector<int> ff(n+1, 0);
        for (pair<int, int> ii:freq)
            ff[ii.second]++;
        int missedCount=0;
        int ans=0;
        for (int c=1; c<=n; c++) {
            ans=max(ans, c*((int)(freq.size())-missedCount));
            missedCount+=ff[c];
        }
        cout<<n-ans<<endl;
    }    
    return 0;
}