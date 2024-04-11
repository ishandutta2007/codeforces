#include<bits/stdc++.h>
#define B 100
#define ll long long
using namespace std;
int S[200009];
int nx[200009];
int v[200009];
main(){
    string s;
    cin >> s;
    int n = s.size();
    ll ans  = 0;
    for(int i = 0; i < s.size(); i++){
        S[i+1] = S[i];
        if(s[i] == '1') S[i+1]++;
    }
    nx[s.size()] = n+1;
    for(int i = s.size()-1; i >= 1; i--){
        nx[i] = nx[i+1];
        if(s[i] == '1') nx[i] = i+1;
    }
    for(int i = 1; i <= B; i++){
        for(int j = 0; j <= n; j++){
            v[j] = i*S[j] - j;
        }
        sort(v,v+n+1);
        int k = 1;
        for(int j = 1; j <= n; j++){
            if(v[j] == v[j-1]) ans+=k, k++;
            else k = 1;
        }
    }
    for(int k = 1; k * (B+1) <= n; k++){
        int j= 1;
        for(int i = 1; i <= n; i++){
            while(j <= n && S[j] - S[i-1] < k) j = nx[j];
             if(j > n) break;
            ans += max(0, (nx[j] - i) / k - (max(j, i+ B*k) -i)/ k);
        }
    }
    cout<<ans<<endl;

}