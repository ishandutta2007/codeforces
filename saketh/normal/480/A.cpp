#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> d[5005];

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;

        d[i] = make_pair(a, b);
    }

    sort(d, d+N);

    int old_done = 0, cur_a = d[0].first;
    int cur_done = 0;

    for(int i=0; i<N; i++){
        if(d[i].first != cur_a){
            old_done = cur_done;
            cur_a = d[i].first;
        }

        if(d[i].second >= old_done) cur_done = max(cur_done, d[i].second);
        else cur_done = max(cur_done, d[i].first);
    }

    cout << cur_done << endl;
    return 0;
}