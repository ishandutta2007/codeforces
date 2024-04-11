#include<bits/stdc++.h>
using namespace std;
int l[200009];
int r[200009];
int s[200009];
main(){
    
    int n,h;
    cin >>n >>h;
    for(int i = 1; i <= n; i++){
        cin>>l[i] >>r[i];
        s[i] = s[i - 1] +r[i] - l[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int lo = i, hi = n;
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            if(r[mid] - l[i] - (s[mid] - s[i - 1]) < h) 
                lo = mid;
            else hi = mid - 1;
        }
        ans = max(ans, h + s[lo] - s[i - 1]);
    }
    cout << ans << endl;
}