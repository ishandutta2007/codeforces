#include<bits/stdc++.h>
using namespace std;
bool cl(int a, int b, int c){
    cout<<2<<" "<<a<<" "<<b<<" "<<c<<endl;
    int x;
    cin>>x;
    if(x == -1) return 0;
    return 1;
}
long long ar(int a, int b, int c){
    cout<<1<<" "<<a<<" "<<b<<" "<<c<<endl;
    long long x;
    cin>>x;
    return x;
}
vector<int> solve(int x, int y, vector<pair<long long,int> > S){
    if(!S.size()) return{};
    sort(S.begin(), S.end());
    vector<int> C;
    int u = S.back().second;
    vector<pair<long long,int > > A,B;
    for(int i = 0; i < S.size()-1; i++){

        if(cl(1,S[i].second,u)) A.push_back(S[i]);
        else B.push_back(S[i]);
    }
    reverse(B.begin(), B.end());
    for(auto x : A)
        C.push_back(x.second);
    C.push_back(u);
    for(auto x : B)
        C.push_back(x.second);
    return C;
}
main(){
    int n;
    cin >> n;
    vector<pair<long long,int> > A,B;
    for(int i = 3; i <= n; i++){
        long long x = ar(1,2,i);
        if(cl(1,2,i)) A.push_back({x,i});
        else B.push_back({x,i});
    }
    vector<int> u = solve(1,2,B), v = solve(2,1,A);

    cout<<0<<" "<<1<<" ";
    for(int x : u)
        cout<<x<<" ";
    cout<<2<<" ";
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;

}