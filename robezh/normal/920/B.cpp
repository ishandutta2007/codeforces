#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n;
int l[1005],r[1005];
P order[1005];
int t[1005];

bool cmp(P a, P b){
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        fill(t, t+1005, 0);
        cin >> n;
        int time = 0;
        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
            order[i].first = l[i], order[i].second = i;
        }
        //for(int i = 0; i < n; i++){cout << l[i] << " " << r[i] << " ";}
        sort(order, order+n, cmp);
        int now = 0;
        for(int i = 0; i < n; i++){
            if(r[order[i].second] < now) continue;
            if(now <= order[i].first){
                t[order[i].second] = order[i].first;
                now = order[i].first + 1;
            }
            else{
                t[order[i].second] = now++;
            };
        }
        for(int i = 0; i < n; i++){
            printf("%d ", t[i]);
        }
        cout << endl;
    }

}