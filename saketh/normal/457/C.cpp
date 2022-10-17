#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, F, A, B;
vector<int> votes[100005];

bool can_win(int v){
    int w = F;
    for(int i=0; i<100000; i++)
        if(votes[i].size() >= v)
            w += votes[i].size() - v + 1;
    return w <= v;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A >> B;
        if(A == 0) F++;
        else votes[A-1].push_back(B);
    }

    int low = F, high = N, lb = N;
    while(low <= high){
        int mid = (low + high) / 2;
        if(can_win(mid)){
            lb = min(lb, mid);
            high = mid-1;
        }
        else low = mid+1;
    }

    priority_queue<int> best_free, rest_free;
    priority_queue<pair<int, int> > forced;

    int free_need = lb - F;
    int cost = 0;

    for(int i=0; i<100000; i++){
        if(votes[i].size() < lb){
            for(int j=0; j<votes[i].size(); j++)
                rest_free.push(-1 * votes[i][j]);
        }
        else{
            int must = votes[i].size() - lb + 1;
            free_need -= must;
            sort(votes[i].begin(), votes[i].end());
            for(int j=0; j<must; j++){
                cost += votes[i][j];
                forced.push(make_pair(-1*(lb-1+must-j), votes[i][j]));
            }
            for(int j=must; j<votes[i].size(); j++)
                rest_free.push(-1 * votes[i][j]);
        }
    }

    for(int i=0; i<free_need; i++){
        cost += -1 * rest_free.top();
        best_free.push(-1 * rest_free.top());
        rest_free.pop();
    }

    int ans = cost;

    for(int tot = (lb+1); tot <= N; tot++){
        while(!forced.empty() && -1 * forced.top().first < tot){
            rest_free.push(-1 * forced.top().second);
            cost -= forced.top().second;
            forced.pop();
        }

        while(best_free.size() < tot-forced.size()-F){
            cost += -1 * rest_free.top();
            best_free.push(-1 * rest_free.top());
            rest_free.pop();
        }

        while(best_free.top() > -1 * rest_free.top()){
            cost -= best_free.top();
            cost += -1 * rest_free.top();
            best_free.push(-1 * rest_free.top());
            rest_free.pop();
            rest_free.push(-1 * best_free.top());
            best_free.pop();
        }

        ans = min(ans, cost);
    }

    cout << ans << endl;
    return 0;
}