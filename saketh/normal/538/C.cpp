#include <iostream>
#include <algorithm>
using namespace std;

const int MAXM = 100005;

int N, M;
int day[MAXM], ht[MAXM];

int ans = 0;

int eval(int i, int j){
    int days = day[j] - day[i];
    int gap = abs(ht[j] - ht[i]);
    if(days < gap) return -1;
    return (days - gap) / 2 + max(ht[i], ht[j]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0; i<M; i++)
        cin >> day[i] >> ht[i];

    for(int i=0; i+1<M; i++){
        int res = eval(i, i+1);
        if(res == -1){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ans = max(ans, res);   
    }

    ans = max(ans, ht[0] + day[0] - 1);
    ans = max(ans, ht[M-1] + N - day[M-1]);
    cout << ans << endl;
}