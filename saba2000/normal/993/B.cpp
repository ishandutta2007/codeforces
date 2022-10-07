#include<bits/stdc++.h>
using namespace std;
int a[1009],b[1009],x[1009],y[1009];
main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin >> a[i]>>b[i];
        if(a[i] > b[i]) swap(a[i],b[i]);
    }


    for(int i = 0; i < m; i++){
        cin >> x[i]>>y[i];
        if(x[i]> y[i]) swap(x[i],y[i]);
    }
    int fl = 1;
    set<int> s;
    for(int i = 0; i < n; i++){
        int X = 0,Y = 0;
        for(int j = 0; j < m; j++){
            if(a[i]== x[j] && b[i] == y[j]) continue;
            if(a[i] == x[j]  || a[i] == y[j]) {X++; s.insert(a[i]);} else
            if(b[i] == x[j]|| b[i] == y[j]) {Y++; s.insert(b[i]);} else
            continue;
        }
        if(X && Y) fl = 0;
    }
    for(int i = 0; i < m; i++){
        int X = 0,Y = 0;
        for(int j = 0; j < n; j++){
            if(a[j]== x[i] && b[j] == y[i]) continue;
            if(a[j] == x[i] || b[j] == x[i]) {X++;} else
            if(a[j] == y[i] || b[j] == y[i]) {Y++;} else
            continue;
        }
        if(X && Y) fl = 0;
    }
    if(s.size() == 1){
        cout<<*(s.begin()) << endl;
    }
    else if(fl) cout<<0<<endl; else cout<<-1<<endl;

}