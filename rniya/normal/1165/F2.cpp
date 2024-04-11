#include <bits/stdc++.h>
using namespace std;
const int MAX=4e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> k(n);
    int sum=0;
    for (int i=0;i<n;++i) cin >> k[i],sum+=k[i];
    vector<set<int>> sale(n);
    for (int i=0;i<m;++i){
        int d,t; cin >> d >> t;
        sale[--t].emplace(-d);
    }
    int lb=0,ub=MAX;
    vector<pair<int,int>> mic;
    while(ub-lb>1){
        int mid=(ub+lb)>>1;
        mic.clear();
        for (int i=0;i<n;++i){
            auto itr=sale[i].lower_bound(-mid);
            if (itr!=sale[i].end()) mic.emplace_back(-(*itr),k[i]);
        }
        sort(mic.begin(),mic.end());
        mic.emplace_back(mid,0);
        int now=0,have=0,rest=sum;
        for (auto p:mic){
            have+=p.first-now; now=p.first;
            int buy=min(have,p.second);
            have-=buy; rest-=buy;
        }
        (rest*2<=have?ub:lb)=mid;
    }
    cout << ub << '\n';
}