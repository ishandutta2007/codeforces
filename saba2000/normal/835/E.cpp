#include<bits/stdc++.h>
using namespace std;
    int n,x,y;
int ask(vector<int> v){
    if(!v.size()) return 0;
 
    cout<<"? "<<v.size()<<" ";
    for(int x :v)
        cout<<x<<" ";
    cout<<endl;
    int t;
    cin>>t;
    if(t == y || (t == (x^y)) ) return 1;
    return 0;
}
main(){
    cin>>n>>x>>y;
    vector<int> w;
    int X = 0;
    int xorr =  0;
    for(int i = 0; i < 10; i++){
        vector<int>v;
        for(int j = 1; j <= n; j++){
           if ((1<<i) & j)
                v.push_back(j);
        }
        int u =ask(v);
        if(u) w = v,xorr+=(1<<i), X = i;
 
    }
    int ans = (1<<X);
    for(int i = 0; i < 10; i++){
        if(i == X) continue;
        vector<int> v;
        for(int j : w){
            if((1<<i) & j) v.push_back(j);
        }
        if(ask(v)) ans += (1<<i);
    }
    int ans2 = ans ^ xorr;
    cout<<"! "<<min(ans,ans2)<<" "<<max(ans,ans2)<<endl;
 
}