#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int> > D ={
{0,0},{-1,0},{-1,1},{-1,2},{0,2},{1,2},{1,1},{1,0}
};
main(){
    int n;
    cin >> n;
    set<pair<int,int> > s;
    for(int i = 0; i <= n; i++){
        int X = 2*i, Y = 0;
        int sg = 1;
        if(i % 2) sg = -1;
        for(auto u : D)
            s.insert({X+u.first, Y + u.second*sg});
        }
    cout<<s.size()<<endl;
    for(auto it =s.begin(); it != s.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
/*
XXXXXX
 X
XXXXXX
 X
XXXXXX

*/