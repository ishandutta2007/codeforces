#include <bits/stdc++.h>
using namespace std;

#define MAXN 200050

int n, tmp;
vector<int> num;
vector<vector<int>> seq(MAXN);
vector<int> last;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &tmp), num.push_back(tmp);

    for(int t : num){
        int pos = lower_bound(last.begin(), last.end(), t, greater<int>()) - last.begin();
        seq[pos].push_back(t);
        if(pos == last.size()){last.push_back(t);}
        else {last[pos] = t;}
    }
    for(int i = 0; i < last.size(); i++){
        for(auto t : seq[i]){
            printf("%d ", t);
        }
        printf("\n");
    }
}