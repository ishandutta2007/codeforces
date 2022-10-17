#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, C, P, K, T;
priority_queue<pair<int, pair<int, int> > > vp;
priority_queue<pair<int, int> > pay;
pair<int, int> tab[1005];

int num = 0, mon = 0;
int out[1005][2];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> C >> P;
        vp.push(make_pair(-1 * C, make_pair(P, i+1)));
    }

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> T;
        tab[i] = make_pair(T, i+1);
    }
    sort(tab, tab+K);

    for(int i=0; i<K; i++){
        while(!vp.empty() && (-1 * vp.top().first) <= tab[i].first){
            pay.push(vp.top().second);
            vp.pop();
        }
        if(!pay.empty()){
            mon += pay.top().first;
            out[num][0] = pay.top().second;
            out[num][1] = tab[i].second;
            pay.pop();
            num++;
        }
    }

    cout << num << " " << mon << endl;
    for(int i=0; i<num; i++)
        cout << out[i][0] << " " << out[i][1] << endl;
    return 0;
}