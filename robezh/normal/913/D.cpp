#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, T;
int a[200050], t[200050];
vector<int> res;
vector<int> good;
bool check(int k){
    res.clear();
    vector<P> time;
    for(int i = 0; i < n; i++){
        if(a[i] >= k) time.push_back(P(t[i],i));
    }
    if(time.size() < k) return false;
    sort(time.begin(), time.end());
    int sum = 0;
    for(int i = 0; i < k; i++) sum += time[i].first, res.push_back(time[i].second);
    if(sum <= T){
        good = res;
        return true;
    }
    return false;
}

int main(){
    scanf("%d%d", &n, &T);
    for(int i = 0; i < n; i++) scanf("%d%d", &a[i], &t[i]);
    int l = -1, r = n+1, mid = (l+r) /2;
    while(l+1 < r){
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
        mid = (r + l) / 2;
        //cout << l << " " << mid << " " << r << endl;
    }
    cout << good.size() << endl;
    cout << good.size() << endl;
    for(int i = 0; i < good.size(); i++) printf("%d ", good[i]+1);

}