#include <iostream>
#include <algorithm>
using namespace std;

int N, V, ans;
pair<int, int> tree[3005];

int main(){
    cin >> N >> V;
    for(int i=0; i<N; i++)
        cin >> tree[i].first >> tree[i].second;
    sort(tree, tree+N);

    int yest = 0, today = 0, idx = 0;

    for(int day = 1; day <= 3001; day++){
        yest = today;
        today = 0;

        while(idx < N && tree[idx].first == day)
            today += tree[idx++].second;

        int can = V;
        ans += min(can, yest);
        can -= min(can, yest);
        ans += min(can, today);
        today -= min(can, today);        
    }

    cout << ans << endl;
    return 0;
}