//
// Created by 54173 on 4/17/2022.
//

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<pii> v;
vector<pii> v2; //Test
pii a[3];
long long mini = 2e18;

int main() {
    cin>>a[0].first>>a[0].second>>a[1].first>>a[1].second>>a[2].first>>a[2].second;
    sort(a,a+3);
    int miny = 1e9,maxy = -1e9;
    for(int i=0;i<3;i++) {
        miny = min(miny,a[i].second);
        maxy = max(maxy,a[i].second);
    }
    cout<<3<<'\n';
    cout<<a[0].first<<' '<<a[0].second<<' '<<a[1].first<<' '<<a[0].second<<'\n';
    cout<<a[1].first<<' '<<miny<<' '<<a[1].first<<' '<<maxy<<'\n';
    cout<<a[1].first<<' '<<a[2].second<<' '<<a[2].first<<' '<<a[2].second<<'\n';
    return 0;
}