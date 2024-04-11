#include<bits/stdc++.h>
using namespace std;
int p[15000009];
int a[300009];
main(){
    int n;
    vector<int> v;
    for(int i = 2; i <= 15e6; i++){
        if(p[i] == 0){
            for(int j = i; j <= 15e6; j+=i){
                p[j] = i;
            }
        }
    }
    cin >> n;
    int G = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        G = __gcd(G, a[i]);
    }
    for(int i = 0; i < n; i++){
        a[i] /= G;
        while(a[i] > 1){
            int P = p[a[i]];
            v.push_back(P);
            while(a[i]%P == 0) a[i]/= P;
        }
    }
    int ans = 0;
    if(v.size() == 0){
        cout<<-1<<endl;
        return 0;
    }
    int cnt = 1;
    sort(v.begin(),v.end());
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]) cnt ++;
        else{
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout<<n - ans << endl;
}