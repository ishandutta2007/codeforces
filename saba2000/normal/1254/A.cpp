#include<bits/stdc++.h>
using namespace std;
int x[2166];
int a[109][109];
char b[109][109];
void solve(){
    int r,c, k;
    cin >> r>>c>>k;
    int s =0;
    for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++){
        char x;
        cin >> x;
        if(x =='R') a[i][j] = 1;
        else a[i][j] = 0;
        s +=a[i][j];

    }
    vector<pair<int,int> > v;
    int u = s / k+1, h = s % k;
    for(int i =0 ; i < r; i++){
        if(i&1)
            for(int j = 0; j < c; j++)
                v.push_back({i,j});
            else
            for(int j = c-1; j >=0; j--)
                v.push_back({i,j});
    }
    int cc = 0, cr = 0;
    if(cc == h) u--;
    for(int i =0 ; i < v.size(); i++){
        int p  =v[i].first, q = v[i].second;
        if(a[p][q] && cr >= u){
            cc++;
            if(cc == h) u--;
            cr = 0;
        }
        b[p][q] = x[cc];
        cr += a[p][q];
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j <c;j++)
            cout<<b[i][j];
        cout<<endl;}

}
main(){
    for(int i = 0; i < 26; i++){
        if(i < 10) x[i+52] = i+'0';
        x[i] = i+'a';
        x[i+26]=i+'A';
    }
    int T;
    cin >> T;
    while(T--){
        solve();
    }


}