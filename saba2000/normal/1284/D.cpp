#include<bits/stdc++.h>
#define ll long long
using namespace std;
int compress(int a[], int l, int r, int k){
    vector<pair<int,int> > v;
    for(int i = l; i <= r; i++)
        v.push_back({a[i], i});
    sort(v.begin(), v.end());
    int c = k;
    for(int i = 0; i < v.size(); i++){
        if(i && v[i].first != v[i-1].first) c++;
        a[v[i].second] = c;
    }
}
int x[500009];
int la[100009],ra[100009],lb[100009],rb[100009];
vector<int> v[1000009];
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d %d",&x[4*i],&x[4*i-1],&x[4*i-2],&x[4*i-3]);
    }

    compress(x,1,4*n,1);
    for(int i = 1; i <= n; i++){
        la[i] =x[4*i];
        ra[i] =x[4*i-1];
        lb[i] =x[4*i-2];
        rb[i] =x[4*i-3];
        v[la[i]].push_back(i);
        v[ra[i]+1].push_back(-i);
    }
    multiset<int> sl,sr;
    for(int i=1; i <= 1e6; i++){
        for(int j : v[i]){
            if(j > 0) sl.insert(lb[j]),sr.insert(rb[j]);
            else sl.erase(sl.find(lb[-j])),sr.erase(sr.find(rb[-j]));
        }
        v[i].clear();
        if(sl.size()==0) continue;
        if(*(--sl.end()) > (*sr.begin())) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    sl.clear(); sr.clear();
    for(int i = 1; i <= n; i++){
        swap(la[i],lb[i]); swap(ra[i],rb[i]);
        v[la[i]].push_back(i);
        v[ra[i]+1].push_back(-i);
    }
    for(int i=1; i <= 1e6; i++){
        for(int j : v[i]){
            if(j > 0) sl.insert(lb[j]),sr.insert(rb[j]);
            else sl.erase(sl.find(lb[-j])),sr.erase(sr.find(rb[-j]));
        }
        if(sl.size()==0) continue;
        if(*(--sl.end()) > (*sr.begin())) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;


}