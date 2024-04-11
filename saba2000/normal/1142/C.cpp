#include<bits/stdc++.h>
using namespace std;
long long x[200009], y[200009];
bool c(long long a, long long b, long long c){
    long long x1 = x[b] - x[a], y1 = y[b] - y[a];
    long long x2 = x[c] - x[a], y2 = y[c] - y[a];
    return (y2 - x2 * x2)*x1 >= (y1 - x1 * x1) * x2;
}
main(){
    long long n;
    cin >> n;
    vector<pair<long long,long long> > v;
    for(long long i =1 ;i <= n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back({x, -y});
    }
    sort(v.begin(), v.end());
    stack<pair<long long,long long> > S;
    for(long long i = 0; i < v.size(); i++){

        x[i] = v[i].first, y[i] =-v[i].second;
        if(i && x[i] == x[i-1]) continue;
        if(S.size() == 0 && x[i] == x[0]) continue;
        if(S.size() == 0 && x[i] != x[0]){
            S.push({0,i});
            continue;
        }
        while(S.size()){
            if(c(S.top().first, S.top().second, i))
                {
                 S.pop();
                }
            else break;
        }
        if(!S.size()) S.push({0,i});
        else S.push({S.top().second, i});
    }
    cout << S.size() << endl;


}