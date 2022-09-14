#include<bits/stdc++.h>

using namespace std;


int n;
const int mx = 1 << 17;
vector<int> t(mx * 2, 0);

void upd(int v){
    if(v == 0)
        return;
    t[v] = t[v * 2] + t[v * 2 + 1];
    upd(v / 2);
}
void st(int v, int d){
    t[mx + v] = d;
    upd((mx + v) / 2);
}
int sum(int v, int l, int r, int cl, int cr){
    if(r < cl || cr < l)
        return 0;
    if(l <= cl && cr <= r)
        return t[v];
    int cm = (cl + cr) / 2;
    return sum(v * 2, l, r, cl, cm) + sum(v * 2 + 1, l, r, cm + 1, cr);
}

int sum(int l, int r){
    if(l <= r)
        return sum(1, l, r, 0, mx - 1);
    return sum(l, n - 1) + sum(0, r);
}

int main(){
    cin >> n;
    vector<pair<int, int>>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> b(1, 0);
    deque<int> c;
    int last = -1;
    for(int i = 0; i < n; i++){
        c.clear();
        c.push_back(a[i].second);
        while(i < n - 1 && a[i + 1].first == a[i].first){
            i++;
            c.push_back(a[i].second);
        }
        if(c.front() < last && c.back() > last){
            while(c.front() < last){
                c.push_back(c.front());
                c.pop_front();
            }
        }
        last = c.back();
        for(int u : c)
            b.push_back(u);
    }
    for(int i = 0; i < n; i++)
        st(i, 1);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += sum(b[i], b[i + 1]);
        st(b[i + 1], 0);
    }
    cout << ans;
}