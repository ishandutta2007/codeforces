#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C[200009];
int st[30];
string s;
bool solve(int x){
    for(int i = 1; i <= x; i++)
        st[i] = 'a';
    for(int i = 0; i < s.size(); i++){
        int u= -1;
        for(int j=  1; j <= x; j++){
            if(s[i] < st[j]) continue;
            if(u == -1 || st[j] > st[u]) u = j;
        }
        if(u ==-1) return 0;
        C[i] = u;
        st[u] = s[i];
    }
    return 1;
}
main(){
    int n;
    cin >> n;
    cin >> s;
    int lo = 2, hi = 2;
    while(lo < hi){
        int mid=(lo+hi)/2;
        if(solve(mid)) hi = mid;
        else lo = mid+1;
    }
    if(solve(lo)){
    cout<<"YES"<<endl;
    for(int i = 0; i < s.size(); i++)
        cout<<C[i]-1;
    cout<<endl;
    }
    else cout<<"NO"<<endl;
}