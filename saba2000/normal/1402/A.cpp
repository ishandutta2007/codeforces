#include<bits/stdc++.h>
using namespace std;
int c[100009];
string a, b;
bool check(int i){
    int ok = 1;
    if(c[i] == 0) ok = 0;
    if(c[i] < 0 && (a[i] == '0' || (i == 0 && a[i] == '1'))) ok = 0;
    if(c[i] < 0 && a[i+1] == '0') ok = 0;
    if(c[i] > 0 && (a[i] == '9' || a[i+1] == '9')) ok = 0;
    return ok;
}
main(){
    int n;
    cin >> n;
    cin>>a>>b;
    long long pas = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) c[i] = b[i]- a[i]; else
        c[i] = (b[i] - a[i]) - c[i-1];
        pas += abs(c[i]);
    }
    if(c[n-1] != 0){
        cout << -1 << endl;
        return 0;
    }
    set<int> s;
    for(int i = 0; i < n-1; i++){
        if(check(i)) {
                s.insert(i);}
    }
    cout << pas << endl;
    for(int _ = 0; _ < min(pas, 100000ll); _++){
        int u = *s.begin();
        if(c[u] < 0){
            cout << u + 1 <<" "<<-1<<endl;
            a[u] --; a[u+1]--; c[u]++;
        }
        else{
            cout<<u+1<<" "<<1<<endl;
            a[u] ++; a[u+1] ++; c[u]--;
        }
        if(!check(u)) s.erase(u);
        if(u-1 > 0){
            if(s.find(u-1) != s.end()) s.erase(u-1);
            if(check(u-1)) s.insert(u-1);
        }
        if(u+1 < n-1){
            if(s.find(u+1) != s.end()) s.erase(u+1);
            if(check(u+1)) s.insert(u+1);
        }
    }



}