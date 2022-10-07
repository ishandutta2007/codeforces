#include<bits/stdc++.h>
#define mid ((l+r)/2)
#define ll long long
using namespace std;
int a[1000009];
main(){
    int n;
    srand(time(0));
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int pas = 0;
    for(int i = 0; i < 25; i++){
        vector<int> v;
        for(int j = 1; j <= n; j++){
            v.push_back(a[j] & ((1 << (i+1)) - 1));
        }
         int ans = 0;
        sort(v.begin(),v.end());
        int j = v.size(), t = v.size()-1,s = v.size();
        for(int k = 0; k < v.size(); k++){
            while(j && v[j-1] + v[k] >= (1<<i)) j--;
            while(t && v[t] + v[k] >= (1<<(i+1))) t--;
            while(s && v[s-1] + v[k] >= (1<<i) + (1<<(i+1))) s--;
           if(v[k] < (1<<i)) ans += (max(0,t - max(j,k+1) + 1))&1;
           else ans += max(0,(int)v.size() - max(s, k+1))&1;
        }
        if(ans & 1) pas += (1 << i);
    }
    cout<<pas<<endl;
}